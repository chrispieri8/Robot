//This library will contain all of the header information for the robot

#ifndef ROBOT
#define ROBOT

//By default the ID of the robot motors will be left_id = 1 and right_id = 2 and the default
//values for both trim will be set to 0

void robotInit(unsigned int address, int left_id, int right_id, int left_trim, int right_trim);
void leftSpeed(int speed);
void rightSpeed(int speed);
void stop();
void forward(int speed, int seconds);
void backward(int speed, int seconds);
void right(int speed, int seconds);
void left(int speeed, int seconds);

#endif
