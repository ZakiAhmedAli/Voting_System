/*
 * main.c
 *
 *  	Created on: Aug 23, 2019
 *      Author: Zaki ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#define F_CPU 8000000UL
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "LCD_interface.h"
#include "string.h"


	u8 counter1=0;
	u8 counter2=0;
	u8 counter3=0;
	u8 counter4=0;
	u8 vote=0;

int main(void) {



	USART_initialization(9600, EIGHT_BITS ,ONE_BIT ,DISABLE_PARITY);

	LCD_VoidInit();


	LCD_VoidWriteString((u8*)"A=0");
	LCD_GoToXy(1,12);
	LCD_VoidWriteString((u8*)"B=0");
	LCD_GoToXy(2,0);

	LCD_VoidWriteString((u8*)"C=0");
	LCD_GoToXy(2,12);
	LCD_VoidWriteString((u8*)"D=0");





while(1)
{
	UART_voidUpdta();

	}
}

	return 0;
}
