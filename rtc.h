

struct time
{
		unsigned char h;
		unsigned char m;
		unsigned char s;
	
};	

void show_rtc_time(struct time t)
{
		lcd_cmd(0x1);
		lcd_data(t.h/16+48);
		lcd_data(t.h%16+48);
		lcd_data(':');	
		lcd_data(t.m/16+48);
		lcd_data(t.m%16+48);
		lcd_data(':');	
		lcd_data(t.s/16+48);
		lcd_data(t.s%16+48);
}


char* print_time(struct time t)
{
		static char s[10];
		s[0]=(t.h/16+48);
		s[1]=(t.h%16+48);
		s[2]=(':');	
		s[3]=(t.m/16+48);
		s[4]=(t.m%16+48);
		s[5]=(':');	
		s[6]=(t.s/16+48);
		s[7]=(t.s%16+48);
		s[8]=0;
			return s;
}

struct time  i2c_rtc_read()
{	
		struct time t;
		t.h=i2c_device_read(0xD0,0x2);
		t.m=i2c_device_read(0xD0,0x1);
		t.s=i2c_device_read(0xD0,0x0);
		msg("timer start read");
	
	return t;
	
}

