#include <REG52.H>
#define TIMER0_VALUE_25mSec 0xA5FF
#define TIMER0_H ((TIMER0_VALUE_25mSec & 0xFF00)>>8)
#define TIMER0_L (TIMER0_VALUE_25mSec & 0x00FF)

sbit led0=P1^0;

void main()
{
	int cnt = 0;
	TMOD = 0x01;
	TH0 = 0xA5;
	TL0 = 0xFF;
	
	TR0 = 1;
	while(1)
	{
		
		//for(i=0;i<=40;i++){
		if(TF0==1){
			TF0=0;
			TH0 = 0xA5;
			TL0 = 0xFF;
			cnt++;
			if(cnt==40)
				{
					led0=~led0;
					cnt=0;
				}
		}
	}
}