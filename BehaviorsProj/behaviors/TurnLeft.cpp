
#include "TurnLeft.h"

TurnLeft::TurnLeft(Robot* robot):Behavior(robot) {

}

TurnLeft::~TurnLeft() {
}

bool TurnLeft::startCond(Point* p)
{
	return true;
}

bool TurnLeft::stopCond(Point* p)
{
	if(this->isInfrontWaypoint(p, 30.0))
		return true;
	else
		return false;
}

void TurnLeft::action()
{
	_robot->setSpeed(0.0, 0.5);
}
