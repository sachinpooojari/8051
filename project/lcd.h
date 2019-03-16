#include<reg51.h>
sfr LCD=0x80;
sbit  RS=P2^0;
sbit RW=P2^1;
sbit EN=P2^2;

void lcd_data(unsigned char ch)
{
	LCD=ch;
	RS=1;
	RW=0;
	EN=1;
	delay(3);
	EN=0;

}


void lcd_cmd(unsigned char ch)
{
	LCD=ch;
	RS=0;
	RW=0;
	EN=1;
	delay(3);
	EN=0;
	

}

void lcd_init()
{
	lcd_cmd(0x1);// to clear screen 
	lcd_cmd(0xE);
	lcd_cmd(0x38);  // to 8 bit mode
		lcd_cmd(0x6);  // to sift right 
	lcd_cmd(0x2);
	


}

void lcd_string(unsigned char *s)
{
		while(*s)
				lcd_data(*s++);
}

void msg(unsigned char *s)
{
	
			lcd_cmd(0x1);
			lcd_string(s);
			delay(50);
			lcd_cmd(0x1);
		}




