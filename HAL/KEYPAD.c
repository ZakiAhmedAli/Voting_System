
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "KEYPAD.h"

#define ROWSIZE  4
#define COLSIZE  4
const u8 KPD_u8value[ROWSIZE][COLSIZE]=
{
		{0x0C , 0x0D , 0x0E , 0x0F},
		{0x08 , 0x09 , 0x0A , 0x0B},
		{0x04 , 0x05 , 0x06 , 0x07},
		{0x00 , 0x01 , 0x02 , 0x03},
};

void KPD_voidInit(void)
{
	//set column as output
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_0 , DIO_U8_OUTPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_1 , DIO_U8_OUTPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_2 , DIO_U8_OUTPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_3 , DIO_U8_OUTPUT);

	//set row as input
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_4 , DIO_U8_INPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_5 , DIO_U8_INPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_6 , DIO_U8_INPUT);
	Dio_VoidSetPinDirection(KEYPAD_PORT , DIO_U8_PIN_7 , DIO_U8_INPUT);

	//active pull up rows pins
	Dio_VoidSetPinValue(KEYPAD_PORT , DIO_U8_PIN_0 , DIO_U8_HIGH);
	Dio_VoidSetPinValue(KEYPAD_PORT , DIO_U8_PIN_1 , DIO_U8_HIGH);
	Dio_VoidSetPinValue(KEYPAD_PORT , DIO_U8_PIN_2 , DIO_U8_HIGH);
	Dio_VoidSetPinValue(KEYPAD_PORT , DIO_U8_PIN_3 , DIO_U8_HIGH);



}

u8 KPD_u8GetPressed(void)
{
	u8 Loc_u8Col;
	u8 Loc_u8Row;

	  /* Initialize the switch status to NOT Pressed */
	u8 Loc_u8Key=NOT_PRESSED;

	for(Loc_u8Col=COL_INIT ; Loc_u8Col< COL_FIN ; Loc_u8Col++)
	{
		Dio_VoidSetPinValue(KEYPAD_PORT , Loc_u8Col , DIO_U8_LOW);
		for(Loc_u8Row=ROW_INIT ; Loc_u8Row <ROW_FIN ; Loc_u8Row++)
		{
			if(!GET_BIT(KEYPAD_PORT ,Loc_u8Row))
			{
				/* Wait until the switch is released (Single Press)*/
				while(!(GET_BIT(KEYPAD_PORT,Loc_u8Row)));

				 Loc_u8Key=KPD_u8value[Loc_u8Row-ROW_INIT][Loc_u8Col-COL_INIT];
		        /* Delay to avoid bouncing                                                                                   */
		        _delay_ms(20);
			}

		}
	}

	return Loc_u8Key;
}
