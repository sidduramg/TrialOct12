

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LCD_Disp.h"
#include "BitsIoLdd1.h"
#include "RS.h"
#include "BitIoLdd2.h"
#include "RW.h"
#include "BitIoLdd3.h"
#include "EN.h"
#include "BitIoLdd1.h"
#include "Row.h"
#include "BitsIoLdd4.h"
#include "Col.h"
#include "BitsIoLdd5.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void LCD_delay(int ms){
	int n;
	int i;
	for(n=0;n<ms;n++){
		for(i=0; i<=0x1ffff; i++);
	}
}

void LCD_command(unsigned char a){
	
	LCD_Disp_PutVal(a);
	RS_PutVal(0);
	RW_PutVal(0);
	EN_PutVal(1);
	LCD_delay(1);
	EN_PutVal(0);
	
}

void LCD_init(){
	LCD_command(0x01);
  //  LCD_command(0x0F);
	LCD_command(0x0C);
	LCD_command(0x38);
	LCD_command(0x80);
	LCD_command(0x06);
	LCD_delay(1);
}

void LCD_data(unsigned char b){
	LCD_Disp_PutVal(b);
	RS_PutVal(1);
	RW_PutVal(0);
	EN_PutVal(1);
	LCD_delay(1);
	EN_PutVal(0);
}

void LCD_puts(unsigned char *str){
	while(*str){
		LCD_data(*str++);
	}
}



/* User includes (#include below this line is not maintained by Processor Expert) */
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void){
	int R=0xff;
	int C=0xff,i=0x80;
	PE_low_level_init();
LCD_init();
LCD_command(0x80);

while(1){
			Row_SetDir(1);
			Col_SetDir(1);
			Row_PutVal(0x0);
			Col_PutVal(0xf);
			Col_SetDir(0);
			C=Col_GetVal();
			Col_SetDir(1);
			Row_PutVal(0xf);
			Col_PutVal(0x0);
			Row_SetDir(0);
			R=Row_GetVal();
			
			LCD_command(i);
			if(R==0x7 && C==0xe){
				LCD_data('a');
				i++;
			}
			
			else if(R==0xb && C==0xe){
				LCD_data('b');
				i++;
			}

			else if(R==0xd && C==0xe){
				LCD_data('c');
				i++;
			}
			
			else if(R==0xe && C==0xe){
				LCD_data('d');
				i++;
			}

			else if(R==0x7 && C==0xd){
				LCD_data('e');
				i++;
			}

			else if(R==0xb && C==0xd){
				LCD_data('f');
				i++;
			}
			
			else if(R==0xd && C==0xd){
				LCD_data('g');
				i++;
			}

			else if(R==0xe && C==0xd){
				LCD_data('h');
				i++;
			}

			else if(R==0x7 && C==0xb){
				LCD_data('i');
				i++;
			}

			else if(R==0xd && C==0xb){
				LCD_data('j');
				i++;
			}

			else if(R==0xb && C==0xb){
				LCD_data('k');
				i++;
			}

			else if(R==0xe && C==0xb){
				LCD_data('l');
				i++;
			}

			else if(R==0x7 && C==0x7){
				LCD_data('*');
				i++;
			}

			else if(R==0xb && C==0x7){
				LCD_data('#');
				i++;
			}
			
			else if(R==0xd && C==0x7){
				
				i--;
				LCD_command(i);
				LCD_data(' ');
			}
			else if(R==0xe && C==0x7){
						
				i=0xc0;	
						LCD_command(i);
						//LCD_data('');
					}
			LCD_delay(1);


		
}
	   	
  
/*lint -restore Enable
 *  MISRA rule (6.3) checking. */

  /* Write your local variable definition here */
	//int l;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

  /*** End of Processor Expert internal initialization.                    ***/
  //i=0;
  
  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
