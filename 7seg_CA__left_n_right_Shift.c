

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
#define seg1 Bits2_PutVal(0xe);
#define seg2 Bits2_PutVal(0xd);
#define seg3 Bits2_PutVal(0xb);
#define seg4 Bits2_PutVal(0x7);


int Seven_Display_ca(int a,int b,int c,int d){
	int i,j;
	for(j=0;j<=100;j++)
		{
	Bits1_PutVal(~a);
	seg1;
	for(i=0;i<=0x7ff;i++);
	Bits1_PutVal(~b);
	seg2;
	for(i=0;i<=0x7ff;i++);
	Bits1_PutVal(~c);
	seg3;
	for(i=0;i<=0x7ff;i++);
	Bits1_PutVal(~d);
	seg4;
	for(i=0;i<=0x7ff;i++);
		}
	return 0;
}


/* User includes (#include below this line is not maintained by Processor Expert) */
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
{
  int i[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  //unsigned char k[4]={0xe,0xd,0xb,0x7};
  int dig,p1,p2,p3,p4,num;
  PE_low_level_init();
 
  num=1234;
  while(1){
	dig=num;
	p1 = dig/1000;
	dig=dig%1000;
	
	p2=dig/100;
	dig=dig%100;
	
	p3=dig/10;
	
	p4=dig%10;
	
	Seven_Display_ca(i[p1],i[p2],i[p3],i[p4]);
	Seven_Display_ca(i[p2],i[p3],i[p4],i[p1]);
	Seven_Display_ca(i[p3],i[p4],i[p1],i[p2]);
	Seven_Display_ca(i[p4],i[p1],i[p2],i[p3]);
	  
	  
	  /*/for(cnt=0;cnt<=9999;cnt++){
		 // for(j=0;j<100;j++){
			
			Seven_Display_ca(i[1]);
			Trigger(k[0]);
			for(a=0;a<=0x7ff;a++);
			
			Seven_Display_ca(i[2]);
			Trigger(k[1]);
			for(a=0;a<=0x7ff;a++);
			
			Seven_Display_ca(i[3]);
			Trigger(k[2]);
			for(a=0;a<=0x7ff;a++);
			
			Seven_Display_ca(i[4]);
			Trigger(k[3]);
			for(a=0;a<=0x7ff;a++);
		  
	  */
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
