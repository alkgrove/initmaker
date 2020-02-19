/**
 * @file timer.c
 * @brief timer routines for TCn timer
 * @details 
 * @copyright Copyright © Alkgrove Electronics 2018 Company Confidential
 * @author Robert Alkire 
 * @date 1/30/2020
 *
 **/
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#ifdef DEBUG
#include <stdio.h>
#endif
#include "sam.h"
#if defined(FEATURE_RTOS) && defined(FEATURE_TIME_SCHEDULER)
#include "RTOSconfig.h"
#else
#define TC_RTOS_NOTIFY_INIT
#define TC_RTOS_NOTIFY
#define TC_RTOS_TAKE
#define TC_RTOS_GIVE
#endif

#ifdef FEATURE_TIME_DELAY
#ifndef TIMER_PORT
#error TIMER_PORT is not defined for FEATURE_TIMER_DELAY. See tc.h for details
#endif
#ifndef TIMER_PORT_FREQUENCY
#error TIMER_PORT_FREQUENCY is not defined for FEATURE_TIMER_DELAY.
#endif
void usDelay(uint32_t us)
{
    timeDelay((TIMER_PORT_FREQUENCY/1000000)*us);
}

void msDelay(uint32_t ms)
{
    timeDelay((TIMER_PORT_FREQUENCY/1000)*ms);
} 
 
uint32_t getTimer(void)
{
    tc_wait_for_sync(TIMER_PORT, TC_SYNCBUSY_CTRLB);
	tc_set_CTRLB(TIMER_PORT, TC_CTRLBSET_CMD_READSYNC);
	while (tc_get_CTRLB(TIMER_PORT, TC_CTRLBSET_CMD_Msk)) {};
	return tccount32_read_COUNT(TIMER_PORT);
}
/** 
 * timeDelay(interval) time delay returns after interval count has elapsed
 * uses TC0 with TC1 slaved configured as a 32 bit timer
 * with 1MHz GCLK, interval is in 1usec, maximum interval is 1Hr 10min or 4294967295 us
 * with 10MHz GCLK, interval is in 0.1usec,  maximum interval is 7min 4.9sec or 429496729.6 us
 * with 100MHz GCLK, interval is in 10nsec,  maximum interval is 21.5s or 42949672960 ns
 **/
void timeDelay(uint32_t interval)
{
	uint32_t count = getTimer();	
	do {
	} while ((getTimer() - count) < interval);
}

#endif

#ifdef FEATURE_TIME_SCHEDULER
#ifndef TIMER_PORT
#error TIMER_PORT is not defined for FEATURE_TIME_SCHEDULER. See tc.h for details
#endif
/* We should have a minimum time period to avoid too short of intervals that 
 * would be hard to catch by interrupt. Default is 1000 or 1ms for a 1MHz clock
 * define MIN_TIMEOUT if different than that. 
 */
#ifndef MIN_TIMEOUT
#define MIN_TIMEOUT 1000
#endif

static timeScheduler_t *root = NULL;
static timeScheduler_t *tail = NULL;
volatile uint32_t matchShadow;  
/* timeSchedulerEvent ccan be used by the callback to 
 * collect bitwise timeout events. It is always cleared on entry
 * to the timer interrupt. 
 * Inside the callback function, declare extern volatile uint32_t timeSchedulerEvent;
 * set bits depending on mask  timeSchedulerEvent |= (1UL << (mask & 0x1F))
 * this can be used by RTOS which use this value to notify a task
 */
volatile uint32_t timeSchedulerEvent;
#ifdef DEBUG
void printSchedule(void)
{
    timeScheduler_t *p = root;
    char str[5];
    char nextstr[5];
    uint8_t ch;
    while (p != NULL) {
        for (int i = 0; i < 4; i++) {
            ch = (uint8_t) ((p->mask >> ((3-i)*8)) & 0xFF);
            str[i] = (char) ((ch > ' ') && (ch < 128) ? ch : '.');
            if (p->next != NULL) {
                ch = (uint8_t) ((p->next->mask >> ((3-i)*8)) & 0xFF);
                nextstr[i] = (char) ((ch > ' ') && (ch < 128) ? ch : '.');
            }
            str[4] = '\0';
            nextstr[4] = '\0';
        }
        printf("%s(%08lX), Match: %08lX, Retrigger: %ld, %s, Next: %s\r\n", str, p->mask, p->match, p->retrigger, 
            p->active ? "Active": "Inactive", (p->next == NULL) ? "NULL" : nextstr);
        p = p->next;
    }
}
#endif

void TIMER_PORT_Handler(void)
{
    timeScheduler_t *p;
    timeScheduler_t *node;
    uint32_t period;
    tc_clear_INTFLAG(TIMER_PORT, TC_INTFLAG_MC0); 
    timeSchedulerEvent = 0;
    TC_RTOS_NOTIFY_INIT;
    while ((root != NULL) && root->active && ((root->match - matchShadow) <= MIN_TIMEOUT)) {
        (*root->callback)(root->mask); /* we have a timeout here, callback */
        period = root->match - matchShadow;
        node = root; /* pop off of the head of list */
        root = root->next;
        node->next = NULL;

        if (node->retrigger > 0) { /* retrigger calculates next interval and inserts back into the lsit */
            period = node->retrigger;
            node->match += period;
            if ((root == NULL) || !root->active || (period <= (root->match - matchShadow))) {
                node->next = root;
                root = node;
            } else {
                p = root;
                while(!((p->next == NULL) || !p->next->active || (period <= (p->next->match - matchShadow)))) {
                    p = p->next;
                }
                node->next = p->next;
                p->next = node;
            }
            if (node->next == NULL) tail = node;
        } else {
            node->active = false; /* inactive timers go at the end of the list */
            tail->next = node;
            if (node->next == NULL) tail = node;
        } 
    }
    /* if no more timers active, halt interrupts */
    if (root->active) {
        matchShadow = root->match;
        tc_wait_for_sync(TIMER_PORT, TC_SYNCBUSY_CC0);
        tccount32_write_CC(TIMER_PORT, 0, matchShadow);
    } else {
        tc_clear_INTEN(TIMER_PORT, TC_INTENSET_MC0);
    }
    TC_RTOS_NOTIFY;
}

timeScheduler_t *attachTimeSchedule(timeScheduler_t *node, void (*callback)(uint32_t), uint32_t mask)
{
    TC_RTOS_TAKE;
    timeScheduler_t *p = root;
    uint8_t inten = tc_get_INTEN(TIMER_PORT, TC_INTENSET_MASK);
    tc_clear_INTEN(TIMER_PORT, TC_INTENSET_MASK);
    /* check if it's in the list already */        
    while(p != NULL) {
        if (p == node) return NULL;
        p = p->next;
    }
    if (callback == NULL) return NULL;
    node->callback = callback;
    node->mask = mask;
    node->match = 0;
    node->retrigger = 0;
    node->active = false;
    node->next = root;
    if (node->next == NULL) tail = node;
    root = node;
    tc_set_INTEN(TIMER_PORT, inten);
    TC_RTOS_GIVE;
    return node;
}

timeScheduler_t *detachTimeSchedule(timeScheduler_t *node)
{
    TC_RTOS_TAKE;
    timeScheduler_t *p = root;
    uint8_t inten = tc_get_INTEN(TIMER_PORT, TC_INTENSET_MASK);
    tc_clear_INTEN(TIMER_PORT, TC_INTENSET_MASK);
    node->callback = NULL;
    if (root == node) {
        root = node->next;
    } else {
        while (p != NULL) {
            if (p->next == node) {
                p->next = node->next;
                break;
            }
            p = p->next;
        }
    }
    tc_set_INTEN(TIMER_PORT, inten);
    TC_RTOS_GIVE;
    return node;
}

/* don't call genericSetTimer directly, use setOneShotTime, setRetriggerTime, clearOneShotTime, clearRetriggerTime */
void genericSetTimer(timeScheduler_t *node, uint32_t period, bool retrigger)
{
    uint32_t count; 
    TC_RTOS_TAKE;
    timeScheduler_t *p = root;
    bool intenclr = tc_get_INTEN(TIMER_PORT, TC_INTENSET_MC0) != TC_INTENSET_MC0;
    tc_clear_INTEN(TIMER_PORT, TC_INTENSET_MC0);
    /* find the node in the list and detach it */
    if (node == root) {
        root = root->next; /* remove it from the head */
    } else {
        while(p != NULL) {
            if (p->next == node) { /* find the parent */
                if (p->next->next == NULL) tail = p;
                p->next = p->next->next; /* remove the node */
                break;
            }
            p = p->next;
        }
    }
    count = getTimer();
    if (period == 0) {
        if(retrigger) {
            /* if clearRetrigger, then stop retrigger and halt the virtual counter */
            node->retrigger = 0;
            node->active = false;
        } else {
            /* if clearOneShot and it's retriggered timer, then reset timer */
            if (node->retrigger > 0) {
                period = node->retrigger;
                node->match = period + count;
                node->active = true;
            } else {
            /* otherwise it is not retrigger and one shot, so halt the virtual timer */
                node->active = false;
            }
        }
    } else {
        node->match = count + period;
        node->retrigger = retrigger ? period : 0;
        node->active = true;
    }
    /* insert back into list */
    if (node->active) {
        if ((root == NULL) || !root->active ||  (period <= (root->match - count))) {
            node->next = root;
            root = node;
        } else {
            p = root;
            while(!((p->next == NULL) || !p->next->active || (period <= (p->next->match - count)))) {
                p = p->next;
            }
            node->next = p->next;
            p->next = node;
        }
        if (node->next == NULL) tail = node;
    } else {
        tail->next = node;
        node->next = NULL;
        if (node->next == NULL) tail = node;
    } 
    /* if the head is not active, then all are not active and exit with interrupts cleared */
    if (root->active) {
        matchShadow = root->match;
        tc_wait_for_sync(TIMER_PORT, TC_SYNCBUSY_CC0);
        tccount32_write_CC(TIMER_PORT, 0, matchShadow);
        /* if counter interrupts were disabled, there can be a bogus interrupt from the timer, clear it */
        if (intenclr) tc_clear_INTFLAG(TIMER_PORT, TC_INTENSET_MC0);
        tc_set_INTEN(TIMER_PORT, TC_INTENSET_MC0);
    }
    TC_RTOS_GIVE;
}
#endif /* FEATURE_TIME_SCHEDULER */  