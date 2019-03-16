#include<reg51.h>

#include<delay.h>
sbit LED =P0^1;
void main()
{
while(1)
{
	LED=0;
	delay(1000);
	LED=1;
	delay(1000);
	
	
	
	
}
	

}