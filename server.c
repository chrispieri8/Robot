//Author: Chris Pieri
//Date: 4/16/2018
//Class: Systems Programming

#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include <math.h>
#include "server.h"


extern void init1(unsigned int address)//Servo_Driver.py init
{
	init2(address);//call second init function
	setALlPWM(0,0);
	write8(__MODE2,__OUTDRV);
	write8(__MODE1,__ALLCALL);
	bcm2835_delay(5);
	int mode1 = readuU8(__MODE1);
	mode1 = mode1 & (~__SLEEP);
	write8(__MODE1, mode1);
	bcm2835_delay(5);
}

extern int init2(unsigned int slave_address)//Adafruit_I2c.py
{
	if(!bcm_2835_init())
	{
		printf("bcm2835_int failed. are you running as root?");
		return 1;
	}

	if(!bcm2835_i2c_begin())
	{
		printf("bcm2835_i2c_begin failed are you running as root?\n");
		return 1;
	}

	bcm2835_i2c_setSlaveAddress(slave_address);
	return 0;
}

extern void setPWMFreq(int freq)
{
	double prescaleval;
	prescaleval = 25000000.0;	//25MHz
	prescaleval /= 4096.0;		//12-bit
	prescaleval /= (float)freq;
	prescaleval -= 1.0;
	prescaleval = floor(prescaleval + 0.5);
	oldmode = readU8(__MODE1);
	newmode = (oldmode & 0x7F) | 0x10;
	write8(__MODE1, newmode);
	write8(__PRESCALE, (int)floor(prescale));
	write8(__MODE1, oldmode);
	sleep(.005);
	write8(__MODE1, oldmode | 0x80);
}

extern void setPWM(int channel, int on, int off)
{
	write8(__LED0_ON_L+4*channel, on & 0xFF);
	write8(__LED0_ON_H+4*channel, on >> 8);
	wirte8(__LED0_OFF_L+4*channel, off & 0xFF);
	write8(__LED0_OFF_H+4*channel, off >> 8);

}


extern setALLPWM(int on, int off)
{
	write8(__ALL_LED_ON_L, on & 0xff);
	write8(__ALL_LED_ON_H, on >>  8);
	write8(__ALL_LED_OFF_L, off & 0xff);
	write8(__ALL_LED_OFF_H, off >> 8);
}


extern void write8(unsigned char reg, unsigned char value)
{
	buffer[0] = reg;
	buffer[1] = value;
	bcm2835_i2c_write (buffer, 2);

}

extern unsigned int readU8(unsigned char reg)
{
	unsigned int result;
	buffer[0] = reg;
	result = bcm2835_i2c_read(buffer, 1);
	return result;

}


