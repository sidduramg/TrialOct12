

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "segments.h"
#include "BitsIoLdd1.h"
#include "start_but.h"
#include "BitIoLdd1.h"
#include "min_but.h"
#include "BitIoLdd2.h"
#include "sec_but.h"
#include "BitIoLdd3.h"
#include "Trig.h"
#include "BitsIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include <string.h>
#include <stdlib.h>
#define seg1 Trig_PutVal(0xe);
#define seg2 Trig_PutVal(0xd);
#define seg3 Trig_PutVal(0xb);
#define seg4 Trig_PutVal(0x7);
//#define flag 1;


int Disp_ca(int a,int b,int c,int d){
	int i,j;
	for(j=0;j<=100;j++)
		{
	segments_PutVal(~a);
	seg1;
	for(i=0;i<=0xfff;i++);
	segments_PutVal(~b);
	seg2;
	for(i=0;i<=0xfff;i++);
	segments_PutVal(~c);
	seg3;
	for(i=0;i<=0xfff;i++);
	segments_PutVal(~d);
	seg4;
	for(i=0;i<=0xfff;i++);
		}
	return 0;
}


/* User includes (#include below this line is not maintained by Processor Expert) */
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
{
  int i[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  //unsigned char k[4]={0xe,0xd,0xb,0x7};
  int p1,p2,p3,p4,j,k;
  unsigned char mm,ss,flag;
  PE_low_level_init();
 
 mm=00;
 ss=00;
 flag=0;

  //t=concat(mm,ss);
while(1){
	 
	
	if(start_but_GetVal()==0){
		//while(start_but_GetVal()==0);
		flag=1;
	  
	}
	  
	if(min_but_GetVal()==0){
		//while(min_but_GetVal()==0);
		mm++;
		p1=mm/10;
		p2=mm%10;
		p3=ss/10;
		p4=ss%10;
		Disp_ca(i[p1],i[p2],i[p3],i[p4]);
		
	}
	
	
	if(sec_but_GetVal()==0){
		//while(sec_but_GetVal()==0);
		ss++;
		p1=mm/10;
		p2=mm%10;
		p3=ss/10;
		p4=ss%10;
		Disp_ca(i[p1],i[p2],i[p3],i[p4]);
	}
	
	if(flag==1)
	{
		for(j=mm;j<=59;j++){
					p1 = j/10;
					p2=j%10;
					for(k=ss;k<=59;k++){
						p3=k/10;
						p4=k%10;
						Disp_ca(i[p1],i[p2],i[p3],i[p4]);
					}
					ss=0;
		}
	}
	
	
	if(flag==0){
		p1=mm/10;
				p2=mm%10;
				p3=ss/10;
				p4=ss%10;
		Disp_ca(i[p1],i[p2],i[p3],i[p4]);
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
