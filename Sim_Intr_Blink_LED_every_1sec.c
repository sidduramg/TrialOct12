#include <REG52.H>
#define TIMER0_VALUE_25mSec 0xA5FF
#define TIMER0_H ((TIMER0_VALUE_25mSec & 0xFF00)>>8)
#define TIMER0_L (TIMER0_VALUE_25mSec & 0x00FF)

sbit led0=P1^0;
//sbit led1 = P1^1;
//unsigned int flag=0;

int cnt1 = 0;

void timer0_internal() interrupt 1
{
	TH0 = 0xA5;
	TL0 = 0xFF;
			if(cnt1==40)
			{
				led0=~led0;
				cnt1=0;
			}
			else
				cnt1++;
	
}

void main()
{
	//cnt2=0;
	TMOD = 0x01;
	TH0 = 0xA5;
	TL0 = 0xFF;
	//TH1 = 0xA5;
	//TL1 = 0xFF;
	TR0=1;
	//TR1=1;
	EA=1;
	ET0=1;
	
	
		while(1)
	{
			
		
	}
}
