sbit SDA=P2^6;
sbit SCL=P2^7;

void i2c_start()
{
	SCL=1;
	SDA=1;
	SDA=0;

	
}

void i2c_ack()
{
		SCL=0;
		SDA=1;
		SCL=1;
		while(SDA==1);
		SCL=0;//fr next operation 	

}

void i2c_stop()
{
	/*	SCL=1;
		SDA=0;
		SDA=1;     //will not work if noack generated ;
	*/
	SCL=0;
	SDA=0;
	SCL=1;
	SDA=1;
//elay(20);
	
}

void i2c_write(unsigned char _data)
{
		signed char i;
	
			
	for(i=7;i>=0;i--)
	{
			SCL=0;
		SDA=(_data &(1<<i)) ? 1 : 0;		
	//	SDA=_data>>i & 1;
			SCL=1;
	}


}
unsigned char i2c_read()
{
	
	int i;	
		unsigned char buffer=0;
	
	//SCL=0; //done at ack mode
		
		for(i=7;i>=0;i--)
	{
		SCL=1;
			if(SDA==1)
					buffer|=(1<<i);
		SCL=0;
	
	}
	return buffer;

}


void i2c_noack()
{
		SCL=0;
		SDA=1;
		SCL=1;

}

