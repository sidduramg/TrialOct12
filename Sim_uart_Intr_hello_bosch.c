#include <reg51.h>
#define Baud_rate 0xFA

//Define Prototypes
void main(void);
void SerialInitialize(void);
//void SendByteSerially(unsigned char ascii);
char *string = "Hello Bosch ";
int Tx_flag=0;
//unsigned char ReceiveByteSerially(void);
/*
void Disp_line(unsigned char *string)
{
	while(*string)
	{
		SendByteSerially(*string);
		string++;
	}
}
*/
void ser_int() interrupt 4
{
	if(TI==1)
	{
		Tx_flag=1;
		TI=0;
	}
		
		
}
//Functions
void main(void)
{
	//unsigned char serialdata;
	ES = 1;
	EA =1;
	
	SerialInitialize();
	
	
	while(1)
	{
		//serialdata = ReceiveByteSerially();
		
			while(*string)
			{
				SBUF = *string++;
				while(Tx_flag==0);
				Tx_flag=0;
			}
		
	}

}


void SerialInitialize(void)
{
	TMOD = ((TMOD & 0x0F) |0x20);
	SCON = 0x50;
	TH1 = Baud_rate;
	TR1 = 1;
}
/*
void SendByteSerially(unsigned char serialdata)
{
	SBUF = serialdata;
	while(TI==0);
	TI=0;
}
*/
/*
unsigned char ReceiveByteSerially(void)
{
	while(RI==0);
	RI = 0;
	return SBUF;
}
*/