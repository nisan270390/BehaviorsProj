
#include "TurnLeft.h"

TurnLeft::TurnLeft(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}

TurnLeft::~TurnLeft() {
	// TODO Auto-generated destructor stub
}

bool TurnLeft::startCond(Point* p)
{
	return true;
}

bool TurnLeft::stopCond(Point* p)
{
	if(this->isInfrontWaypoint(p))
		return true;
	else
		return false;
}

void TurnLeft::action()
{
	_robot->setSpeed(0.5, 0.0);
}
