#include"delay.h"
#include<reg51.h>
#include"lcd.h"
#include"i2c_bit.h"
#include"i2c_frame.h"
#include"EEPROM.h"
#include"rtc.h"


void main()
{			int i;	
			struct time t;
			lcd_init();
			lcd_string("Welcome");
			delay(500);
			lcd_cmd(0x1);
	
	for(i=0;i<5;i++)
	{
				t=i2c_rtc_read();
				//show_rtc_time(t);
		//		lcd_string(print_time(t));	
				i2c_EEPROM_write(print_time(t));
				
	}
 i2c_EEPROM_read();
/*
	i2c_EEPROM_clear(	0xA0);
	i2c_EEPROM_write("hai hello how are  ");
	
	
	
	
	 i2c_EEPROM_read();
*/	
while(1);
}