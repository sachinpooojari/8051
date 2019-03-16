#include "delay.h"
#include "lcd.h"


void main()
{
	
	
	char ch ='a';
	lcd_init();
	while(1)
	{
	lcd_string("Welcome");
	delay(1000);
	lcd_cmd(0x1);
	}
	
  
	
	



}