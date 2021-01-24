

#ifndef  _KEYPAD_H
#define  _KEYPAD_H





/***************************************** Macros *****************/
#define KEYPAD_PORT		DIO_U8_PORT_D

#define COL_INIT       0

#define COL_FIN        4

#define ROW_INIT       4

#define ROW_FIN        8

#define NOT_PRESSED    0
/*******************************************************************/


void KPD_voidInit(void);

u8 KPD_u8GetPressed(void);


#endif

