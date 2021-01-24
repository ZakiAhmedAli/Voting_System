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
	vote = USART_u8RXChar();

	if(vote == 1+48)
	{
		counter1++;
		LCD_GoToXy(1,2);
		LCD_VoidWriteNum(counter1);
	}
	else if(vote == 2+48)
	{
		counter2++;
		LCD_GoToXy(1,14);
		LCD_VoidWriteNum(counter2);
	}
	else if(vote == 3+48)
	{
		counter3++;
		LCD_GoToXy(2,2);
		LCD_VoidWriteNum(counter3);
	}
	else if(vote == 4+48)
	{
		counter4++;
		LCD_GoToXy(2,14);
		LCD_VoidWriteNum(counter4);
	}
	else if(vote == '0' )
	{
		if(counter1 > counter2 && counter1 > counter3 &&counter1 > counter4)
		{
			LCD_voidClear();
			LCD_VoidWriteString((u8*)"A is the Win");
		}
		if(counter2 > counter1 && counter2 > counter3 &&counter2 > counter4)
		{
			LCD_voidClear();
			LCD_VoidWriteString((u8*)"B is the Win");
		}
		if(counter3 > counter1 && counter3 > counter2 &&counter3 > counter4)
		{
			LCD_voidClear();
			LCD_VoidWriteString((u8*)"C is the Win");
		}
		if(counter4 > counter2 && counter4 > counter3 &&counter4 > counter1)
		{
			LCD_voidClear();
			LCD_VoidWriteString((u8*)"D is the Win");
		}

		_delay_ms(2000);
		LCD_voidClear();
		counter1 = counter2 =counter3=counter4=0;
		LCD_VoidWriteString((u8*)"A=0");
		LCD_GoToXy(1,12);
		LCD_VoidWriteString((u8*)"B=0");
		LCD_GoToXy(2,0);

		LCD_VoidWriteString((u8*)"C=0");
		LCD_GoToXy(2,12);
		LCD_VoidWriteString((u8*)"D=0");

	}
}

	return 0;
}
