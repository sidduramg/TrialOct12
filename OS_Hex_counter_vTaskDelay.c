/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-11-04, 14:12, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "FRTOS1.h"
#include "UTIL1.h"
#include "MCUC1.h"
#include "Led_main.h"
#include "BitsIoLdd1.h"
#include "seven_ca.h"
#include "BitsIoLdd2.h"
#include "seven_cc.h"
#include "BitsIoLdd3.h"
#include "Led_low.h"
#include "BitsIoLdd4.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
unsigned int i;
unsigned char a[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7f,0x39,0xbf,0x79,0x71};
/* User includes (#include below this line is not maintained by Processor Expert) */
/*
void delay(unsigned int ms){
	int i,j;
	for(j=0;j<=ms;j++){
		for(i=0;i<0x7ffff;i++);
	}
}
*/
void Task1()
{

	unsigned char j,k;
	while(1)
	{
		j=0x8;
		for(k=0;k<=4;k++){
			Led_main_PutVal(j);
			//for(i=0;i<=0x1ffff;i++);
			vTaskDelay(1000/portTICK_PERIOD_MS);
			j=j>>1;
		}
		j=0x8;
		for(k=0;k<=4;k++){
			Led_low_PutVal(j^0xf);
			vTaskDelay(1000/portTICK_PERIOD_MS);
			j=j>>1;
		}
		
	}
}

void Task2()
{
	unsigned char k;

	while(1)
	{
			//j=0;
			for(k=0;k<=15;k++){
				seven_ca_PutVal(a[k]);
				vTaskDelay(500/portTICK_PERIOD_MS);
				//j++;
			}
	}
}

void Task3()
{
	unsigned char k;

	while(1)
	{
			//j=0;
			for(k=0;k<=15;k++){
				seven_cc_PutVal(~a[k]);
				vTaskDelay(1000/portTICK_PERIOD_MS);
				//j=j>>1;
			}
	}
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  xTaskCreate(Task1, "Task1", 100, NULL, 11, NULL);
  xTaskCreate(Task2, "Task2", 100, NULL, 11, NULL);
  xTaskCreate(Task3, "Task3", 100, NULL, 11, NULL);

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
