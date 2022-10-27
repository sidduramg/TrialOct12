
/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "seven_ca.h"
#include "BitsIoLdd1.h"
#include "Trig.h"
#include "BitIoLdd2.h"
#include "seven_cc.h"
#include "BitsIoLdd3.h"
#include "Led_cc.h"
#include "BitsIoLdd4.h"
#include "Led_ca.h"
#include "BitsIoLdd5.h"
#include "Interrupt_1.h"
#include "ExtIntLdd1.h"
#include "Interrupt_2.h"
#include "ExtIntLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void delay(){
	int i;
	for(i=0;i<=0x7ffff;i++);
}

void led_cc(){
	int i,j=0x8;
	for(i=0;i<=3;i++){
		Led_cc_PutVal(j);
		j=j>>1;
		delay();
		Led_cc_PutVal(0);
	}
}

void led_ca(){
	int i,j=0x8;
	for(i=0;i<=3;i++){
		Led_ca_PutVal(j ^ 0xf);
		j=j>>1;
		delay();
		Led_ca_PutVal(0xf);
	}
}

/* User includes (#include below this line is not maintained by Processor Expert) */
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void){
	
	PE_low_level_init();
	
	while(1){
		
		led_cc();
		led_ca();
	
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
