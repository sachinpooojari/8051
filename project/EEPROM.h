#include<stdio.h>

			
void i2c_EEPROM_clear(	unsigned char addr)
{
		
	
			unsigned char memadd=0x0;
			msg("clearring..");
			while(memadd<255)
			{	
		
				i2c_device_write(addr,memadd++,0);
		}
			msg("clear doen");
}


void i2c_EEPROM_write(unsigned char *s)
{		

			unsigned char addr=0xA0;
			static unsigned char memadd=0x0;
			msg("writing");	
	
			i2c_device_write(addr,memadd++,'*');
	
			while(*s)
			{		
				i2c_device_write(addr,memadd++,*s);
				s++;
			}
			
			
				
			msg("writing done");
	}


void i2c_EEPROM_read()
{
		unsigned char addr=0xA0;
			
		unsigned char temp='a';
		unsigned char memadd=0x0;
		unsigned char flg=0;
			msg("reaading...");
		
			while(temp!=0)
			{
				
				
					temp=i2c_device_read(addr,memadd++);
					if(temp=='*')
					{		
							delay(100);
							if(flg==0)
							{	lcd_cmd(0x80);
									flg=1;
							}
							else
							{
									lcd_cmd(0xC0);
									flg=0;
							}
							continue;
					}	
					
					lcd_data(temp);
					
			}		
			delay(1000);
			msg("reading done...");

}
