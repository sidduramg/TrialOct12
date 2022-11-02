#include<reg51.h>
#define LED P1
#define DIP P2
main()
{
	int i,j,k;
	while (1)
	{
		j=0X01;
		for (i=0;i<=7;i++){
		LED=j^0xff;
		for(k=0;k<=100;k++);
		j=j<<1;
		
		}
	}
}