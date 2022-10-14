#include <reg51.h>
//sbit led P1;
#define LEDS P1

main(){
	unsigned char i,j,k;
	while (1)
	{
		
		j=0x80;
		for(k=0;k<=7;k++){
			LEDS = j^0xff;
			for (i=0; i<100; i++);
			j=j>>1;
		}
	}
}
