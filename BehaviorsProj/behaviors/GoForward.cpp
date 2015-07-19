

#include "GoForward.h"

GoForward::GoForward(Robot* robot):Behavior(robot) {

}

GoForward::~GoForward() {
}

bool GoForward::startCond(Point* p)
{
	if(this->isInfrontWaypoint(p, 15.0))
		return true;
	else
		return false;
}

bool GoForward::stopCond(Point* p)
{
	if(!this->isInfrontWaypoint(p, 15.0))
		return true;
	else
		return false;
}

void GoForward::action()
{
	_robot->setSpeed(0.5, 0.0);
}
