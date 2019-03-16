#include<reg51.h>
#include"delay.h"
sfr LCD=0x80;
sbit RS=P2^0;
sbit RW=P2^1;
sbit EN=P2^2;

sbit r0=P2^3;
sbit r1=P2^4;
sbit r2=P2^5;
sbit r3=P2^6;
sbit c0=P3^0;
sbit c1=P3^1;
sbit c2=P3^2;
sbit c3=P3^3;

unsigned char  matrix()
{
	
	unsigned char row,col;
	char key[4][4]={'1','2','3','4',
								'5','6','7','8',
								'9','A','B','C',
									'D','E','F','G'};
	r0=r1=r2=r3=0;
	c0=c1=c2=c3=1;
	while((c1&c2&c3&c0)==1);
	r0=0;
	r1=r2=r3=1;
									if((c1&c2&c3&c0)==0)
									{
										row=0;
										goto check;
									}
									
	r1=0;
	r0=r2=r3=1;
								if((c1&c2&c3&c0)==0)
									{
										row=1;
										goto check;
									}
	r2=0;
	r1=r0=r3=1;
									if((c1&c2&c3&c0)==0)
									{
										row=2;
										goto check;
									}



	r3=0;
	r1=r2=r0=1;
									if((c1&c2&c3&c0)==0)
									{
										row=3;
										goto check;
									}

	check:
									if(c0==0)
											col=0;
									else if(c1==0)
											col=1;
									else if(c2==0)
											col=2;
									else if(c3==0)
											col=3;
									
		while((c1&c2&c3&c0)==0);
								return key[row][col];
								

}



void lcd_data(unsigned char ch)
{
	LCD=ch;
	RS=1;
	RW=0;
	EN=1; // lcd start 
	delay(2);
	EN=0;   // clear fr next
	

}


void lcd_cmd(unsigned char ch )
{
		LCD=ch;
		RS=0;
		RW=0; 
		EN=1;
		delay(2);
		EN=0;
	
}


void lcd_init(void )
{
	
	lcd_cmd(0x1); //clear
	lcd_cmd(0x2); //home
	lcd_cmd(0x6) ;//right shift 
	lcd_cmd(0x38) ;  //8bit mode 
	lcd_cmd(0xE) ;;//enable cursor
	lcd_cmd(0xF) ;//blink
 	
}


void main()
{
	lcd_init();
	while(1)
	{
	lcd_data(matrix());
	//lcd_cmd(0x2);
	}



}