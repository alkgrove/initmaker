/**********************************************************
 * blinky.c
 * well it blinks an LED
 *********************************************************/
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "sam.h"
#include "delay.h"
#include "uart.h"
#include "cli.h"

void SysTick_Handler(void)
{
    gpio_toggle_out(LEDRED);
}

typedef enum {cmd_invalid = -1, cmd_hex, cmd_beer, cmd_swo, cmd_echo, cmd_debug, cmd_help} command_t;;
const commandList_t commandList[] = {
	{cmd_hex, "hex", NULL, "Print text as hexadecimal"},
	{cmd_beer, "beer", "b", "Print 99 bottles of beer"},
	{cmd_swo, "swo", "s", "Print to SWO port"},
	{cmd_echo, "echo", "e", "Echo what you typed"},
	{cmd_help, "help", "?", "Print Help Information"}};
	
int main(void)
{
	serin = COM3;
	serout = COM3;
	static char CommandLine[80];
	char *nextArgument;
	command_t cmd;
	char *p;
	int beer;
	printf("Test UART Program\r\n");
	while (true) {
		printf("\r\n> ");
  		nextArgument = CommandLine;
		fgets(CommandLine, sizeof(CommandLine), serin);
    	printf("\n");
  		p = nextToken(&nextArgument);
  		cmd = searchCommand(p, commandList, sizeof(commandList)/sizeof(commandList_t));

		switch(cmd) {
			case cmd_invalid:
				printf("Unknown command\r\n");
			break;
			case cmd_hex:
				dump_mem((uint8_t *)nextArgument, strlen(nextArgument));
			break;
			case cmd_echo:
				printf("%s", nextArgument);
			break;
			case cmd_beer:
				beer = 99;
				do {
					delay_us(1000000);
     				printf("%d bottles of beer on the wall, %d bottles of beer, take one down, pass it around\r\n",(int) beer, (int) beer);
    			} while(--beer > 0);
    		break;
    		case cmd_swo:
//    			fprintf(SWO1, "%s\r\n", nextArgument);
			break;
    		case cmd_help:
				printHelp(commandList, sizeof(commandList)/sizeof(commandList_t));
			break;
			default:
			break;
		}
	}
}
