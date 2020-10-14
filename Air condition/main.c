/*
 * Air condition.c
 *
 * Created: 10/10/2020 8:38:13 PM
 * Author : Ibrahim
 */ 


#include "Temprature_Sensor.h"
#include "DC_Motor.h"
#include "LCD.h"

extern uint16 ADC_value;

int main(void)
{
	uint16 temp = 0;
	
	LCD_Init();
	Tempsensor_Init();
	DC_Motor_Init();
	
	
	/* Replace with your application code */
	while (1)
	{
		#if ADC_INTERRUPT_SATATE == ADC_INTERRUPT_ENABLE
		temp = ADC_value;
		#endif
	
		Tempsensor_Read(&temp);
		LCD_GoTo(0,0);
		LCD_WriteString("Temp: ");
		LCD_Write_Intiger(temp);
		LCD_WriteString("    ");
		
		
		Control_DC(&temp);
		
	}
}


void Control_DC(uint16* temp)
{
		if (*temp <= 10)
		{
			DC_Motor_SetSpeed(0);
			DC_Motor_Stop();
			LCD_GoTo(1,0);
			LCD_WriteString("Fan: Off ");
		}
		else if (*temp > 10 && *temp <=20)
		{
			
			DC_Motor_SetSpeed(3);
			DC_Motor_SetDirection(ANTI_CLOCKWISE);
			DC_Motor_Start();
			LCD_GoTo(1,0);
			LCD_WriteString("Fan:3/10 ");
			
		}
		else if (*temp > 20 && *temp <=25)
		{
			DC_Motor_SetSpeed(5);
			DC_Motor_SetDirection(ANTI_CLOCKWISE);
			DC_Motor_Start();
			LCD_GoTo(1,0);
			LCD_WriteString("Fan:5/10 ");
		}
		else if (*temp > 25 && *temp <=30)
		{
			DC_Motor_SetSpeed(8);
			DC_Motor_SetDirection(ANTI_CLOCKWISE);
			DC_Motor_Start();
			LCD_GoTo(1,0);
			LCD_WriteString("Fan:8/10 ");
		}
		else if (*temp > 30)
		{
			DC_Motor_SetSpeed(10);
			DC_Motor_SetDirection(ANTI_CLOCKWISE);
			DC_Motor_Start();
			LCD_GoTo(1,0);
			LCD_WriteString("Fan:10/10");
		}
		
}
