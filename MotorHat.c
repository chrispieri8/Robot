#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "MotorHat.h"
#include "server.h"

void dcInit()
{
	int MC;
	int controller; 
	int num;
	MC = controller;
	int motornum = num;
	int pwm = 0;
	int in1 = 0;
	int in2 = 0;

	if(num == 0)
	{
		pwm = 8;
		in2 = 9;
		in1 = 10;
	}
	else if(num == 1)
	{
		pwm = 13;
		in2 = 12;
		in1 = 11;
	}
	else if(num == 2)
	{
		pwm = 2;
		in2 = 3;
		in1 = 4;
	}
	else if(num == 3)
	{
		pwm = 7;
		in2 = 6;
		in1 = 5;
	}
	else
	{
		printf("MotorHat Motor must be between 1 and 4 inclusive");
		int PWMpin = pwm;
		int IN1pin = in1;
		int IN2pin = in2;
	}
}

void run(int command)
{
	int IN1pin;
	int IN2pin;
	if(command == FORWARD)
	{
		setPin(IN2pin, 0);
		setPin(IN1pin, 1);
	}
	if(command == BACKWARD)
	{
		setPin(IN1pin, 0);
		setPIn(IN2pin, 1);
	}
	if(command == RELEASE)
	{
		setPin(IN1pin, 0);
		setPin(IN2pin, 0);
	}

}

void setSpeed(int speed)
{
	int PWMpin;
	if(speed < 0)
	{
		speed = 0;
	}
	if(speed > 255)
	{
		speed = 255;
	}
	setPWM(PWMpin, 0, speed*16);

}

void hatInit(int addr, int freq)
{
	int _frequency;
	int _pwm;
	_frequency = freq;
	//motors
	_pwm = PWM(addr, 0);
	setPWMFreq(_frequency);
}

void setPin(int pin, int value)
{
	if(pin < 0 || pin > 15)
	{
		printf("PWM pin must be between 0 and 15 inclusive");
	}
	if(value != 0 && value != 1)
	{
		printf("Pin value must be 0 or 1");
	}
	if(value == 0)
	{
		setPWM(pin, 0, 4096);
	}
	if(value == 1)
	{
		setPWM(pin, 4096, 0);
	}
}

motor getMotor(int num)
{
	if(num < 1 || num > 4)
	{
		printf("MotorHAT Motor must be between 1 and 4 inclusive");
	}
	return list[num-1];
}
