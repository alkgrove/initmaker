/**********************************************************
 * blinky.c
 * well it blinks an LED
 *********************************************************/
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include "sam.h"
#ifdef metrom4
#include "metrom4_init.h"
#endif
#ifdef itsym4
#include "itsym4_init.h"
#endif
#ifdef featherm4
#include "featherm4_init.h"
#endif

void SysTick_Handler(void)
{
    gpio_toggle_out(LEDRED);
}

int main(void)
{
	while (true) {
	}
}
