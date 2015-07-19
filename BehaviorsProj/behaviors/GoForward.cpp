

#include "GoForward.h"

GoForward::GoForward(Robot* robot):Behavior(robot) {

}

GoForward::~GoForward() {
}

bool GoForward::startCond(Point* p, Particle* par)
{
	if(this->isInfrontWaypoint(p, 2.0, par))
		return true;
	else
		return false;
}

bool GoForward::stopCond(Point* p, Particle* par)
{
	if(!this->isInfrontWaypoint(p, 20.0, par))
		return true;
	else
		return false;
}

void GoForward::action()
{
	_robot->setSpeed(0.5, 0.0);
}
