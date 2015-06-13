/*
 * Robot.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#include "Robot.h"

Robot::Robot(char* ip, int port) {
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_pp->SetMotorEnable(true);
	//For fixing Player's reading BUG
	for(int i=0;i<15;i++)
		Read();
}

bool Robot::isFree(int startIndex, int endIndex, float distance)
{
	bool free = true;
	for(int i = startIndex; i<=endIndex; i++)
	{
		float dist = (*_lp)[i];

		if(dist < distance)
		{
			free = false;
			break;
		}
	}
	return free;
}

Robot::~Robot() {
	delete _pc;
	delete _pp;
	delete _lp;
}
