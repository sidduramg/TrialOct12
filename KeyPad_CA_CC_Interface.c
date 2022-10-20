

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Row.h"
#include "BitsIoLdd1.h"
#include "LED.h"
#include "BitsIoLdd4.h"
#include "Col.h"
#include "BitsIoLdd5.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"




/* User includes (#include below this line is not maintained by Processor Expert) */
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
{
/*	int row[4]={0x1,0x2,0x4,0x8};
	int col[4]={0xe,0xd,0xb,0x7};
	//unsigned char ;*/
	int C,R;
	
  
	PE_low_level_init();
while(1){
	Row_SetDir(1);
	Col_SetDir(1);
	LED_PutVal(0x0f);
	Col_SetDir(0);
	C=Col_GetVal();
	Row_SetDir(0);
	R=Row_GetVal();
	R=R<<4;
	LED_PutVal(R+C);
	
	
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
