
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
#include "Set.h"
#include "BitIoLdd4.h"
#include "Inc.h"
#include "BitIoLdd5.h"
#include "Dec.h"
#include "BitIoLdd6.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

unsigned int hr,min,sec;

void LCD_delay(int ms){
	int n;
	int i;
	for(n=0;n<ms;n++){
		for(i=0; i<=0xffff; i++);
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
//    LCD_command(0x0F);
	LCD_command(0x0C);
	LCD_command(0x30);
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

void LCD_Run(unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6){
		LCD_command(0x80);
		LCD_data(p1+48);
		LCD_data(p2+48);
		LCD_data(':');
		LCD_data(p3+48);
		LCD_data(p4+48);
		LCD_data(':');
		LCD_data(p5+48);
		LCD_data(p6+48);
}
void display(unsigned int H, unsigned int M, unsigned int S){
	int i, j, k, l, m , n;
	i=H/10;
	j=H%10;
	k=M/10;
	l=M%10;
	m=S/10;
	n=S%10;
	LCD_Run(i,j,k,l,m,n);
}
void unpack(unsigned int HH, unsigned int MM, unsigned int SS){
	display(HH, MM, SS);
}

void LCD_Set_Mode(unsigned int a){
	//unsigned int i, j, k;
	while(a==1){
		if(Inc_GetVal()==0){
			while(Inc_GetVal()==0);
			hr++;
		}
		if(Dec_GetVal()==0){
			while(Dec_GetVal()==0);
			hr--;
		}
		if(Set_GetVal()==0){
			while(Set_GetVal()==0);
			a++;
		}
		display(hr,min,sec);
		
	}
	while(a==2){
		if(Inc_GetVal()==0){
				while(Inc_GetVal()==0);
				min++;
			}
			if(Dec_GetVal()==0){
				while(Dec_GetVal()==0);
				min--;
		}
		if(Set_GetVal()==0){
				while(Set_GetVal()==0);
				a++;
			}
		display(hr,min,sec);
	}
	while(a==3){
		if(Inc_GetVal()==0){
				while(Inc_GetVal()==0);
				sec++;
			}
			if(Dec_GetVal()==0){
				while(Dec_GetVal()==0);
				sec--;
		}
		if(Set_GetVal()==0){
				while(Set_GetVal()==0);
				a++;
			}
		display(hr,min,sec);
	}
}

/* User includes (#include below this line is not maintained by Processor Expert) */
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void){
	unsigned int flag=0;
	unsigned int i;
	PE_low_level_init();
LCD_init();
LCD_command(0x80);
i=0;
hr=00;
min=00;
sec=00;

while(1){
		unpack(hr,min,sec);
		if(Set_GetVal()==0){
			while(Set_GetVal()==0);
			i++;
			flag=1;
		}
		
		while(flag==1){
			LCD_Set_Mode(i);
			
			/*
			if(Set_GetVal()==0){
				while(Set_GetVal()==0);
				i++;
			}
			*/
			i=0;
			flag=0;
			unpack(hr,min,sec);
		}
		
		if(sec==60){
			sec=00;
			min++;
		}
		if(min==60){
			min=00;
			hr++;
		}
		if(hr==24){
			hr=00;
		}
		sec++;
		LCD_delay(19);
		
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
