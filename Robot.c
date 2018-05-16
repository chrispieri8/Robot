#include "Robot.h"
#include "server.h"
#include "MotorHat.h"
#include <stdlib.h>
#include <stdio.h>

void robotInit(unsigned int address, int left_id, int right_id, int left_trim, int right_trim)
{
	int _mh, _left_trim, _right_trim;
	_mh = address;
	motor _left, _right;
	_left = getMotor(left_id);
	_right = getMotor(right_id);
	_left = left_id;
	_right = right_id;
	_left_trim = left_trim;
	_right_trim = right_trim;
	run(RELEASE);


}

void leftSpeed(int speed)
{

	if(speed >= 0 && speed <= 255)
	{
		speed +=

}

void rightSpeed(int speed)
{
	if(speed >= 0 && speed <= 255)
        {
                speed +=

}

void stop()
{
	run(RELEASE);
}

void forward(int speed, int seconds)
{
	leftSpeed(speed);
	rightSpeed(speed);
	run(FORWARD);

}

void backward(int speed, int seconds)
{
	leftSpeed(speed);
	rightSpeed(speed);
	run(BACKWARD);

}

void right(int speed, int seconds)
{
	leftSpeed(speed);
	rightSpeed(speed);
	
}
