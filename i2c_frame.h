
void i2c_device_write(unsigned char SA,unsigned char MA,unsigned char _data)
{
	
		i2c_start();
		i2c_write(SA);
		i2c_ack();
		i2c_write(MA);
		i2c_ack();
		i2c_write(_data);
		i2c_ack();
		i2c_stop();
		delay(20);
}

unsigned char i2c_device_read(unsigned char SA,unsigned char MA)
{
	unsigned char  buffer;
		i2c_start();
		i2c_write(SA);
		i2c_ack();
		i2c_write(MA);
		i2c_ack();
		i2c_start();
		i2c_write(SA|1);
		i2c_ack();
		buffer=i2c_read();
		i2c_noack();
		i2c_stop();
return buffer;

}
