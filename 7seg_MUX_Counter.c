

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "Bits2.h"
#include "BitsIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"


int Seven_Display_ca(int a){
	Bits1_PutVal(~a);
	return 0;}
int Seven_Display_cc(int b){
    Bits2_PutVal(b);
	return 0;	
}
int Trigger(int c){
	Bits2_PutVal(c);
	return 0;
}
/* User includes (#include below this line is not maintained by Processor Expert) */
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
{
  int i[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  unsigned char k[4]={0xe,0xd,0xb,0x7},j;
  int cnt,a,dig,temp;
  PE_low_level_init();
 
  
  while(1){
	  for(cnt=0;cnt<=9999;cnt++){
		  for(j=0;j<100;j++){
			dig=cnt;
			temp = dig/1000;
			dig=dig%1000;
			Seven_Display_ca(i[temp]);
			Trigger(k[0]);
			for(a=0;a<=0x7ff;a++);
			temp=dig/100;
			dig=dig%100;
			Seven_Display_ca(i[temp]);
			Trigger(k[1]);
			for(a=0;a<=0x7ff;a++);
			temp=dig/10;
			Seven_Display_ca(i[temp]);
			Trigger(k[2]);
			for(a=0;a<=0x7ff;a++);
			temp=dig%10;
			Seven_Display_ca(i[temp]);
			Trigger(k[3]);
			for(a=0;a<=0x7ff;a++);
		  }
	  }
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
