

#include "GoForward.h"

GoForward::GoForward(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}

GoForward::~GoForward() {
	// TODO Auto-generated destructor stub
}

bool GoForward::startCond(Point* p)
{
	if(this->isInfrontWaypoint(p))
		return true;
	else
		return false;
}

bool GoForward::stopCond(Point* p)
{
	if(!this->isInfrontWaypoint(p))
		return true;
	else
		return false;
}

void GoForward::action()
{
	_robot->setSpeed(0.5, 0.0);
}
