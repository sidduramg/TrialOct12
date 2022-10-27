#include <reg51.h>

#define led_main P0
#define led_intr0 P1
#define led_intr1 P2
//sbit sw1 = P2^0;
//sbit sw2 = P2^1;


/*#define LED1 P0;
#define LED2 P1;
#define LED3 P2;
*/
void delay(){
	int i,j;
	for(i=0;i<=10000;i++){
		for(j=0;j<1000;j++);
	}
}

void intr0_external() interrupt 0
{
	unsigned char j,k;
		j=0x80;
		for(k=0;k<=7;k++){
			led_intr0 = j^0xff;
			delay();
			j=j>>1;
		}
}

void intr1_extarenal() interrupt 2
{
	unsigned char j,k;
	j=0x80;
		for(k=0;k<=7;k++){
			led_intr1 = j^0xff;
			delay();
			j=j>>1;
		}
}

void main(){
	unsigned char j,k;
	EA = 1;
	EX0 = 1;
	EX1 = 1;
	IT1 = 1;
	IT0 = 1;
	//sw1 = P3^2;
	//sw2 = P3^3;
	
	while (1)
	{
		j=0x80;
		for(k=0;k<=7;k++){
			led_main = j^0xff;
			delay();
			j=j>>1;
		}
	}
		
	}