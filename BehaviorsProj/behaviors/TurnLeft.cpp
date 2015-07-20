
#include "TurnLeft.h"

TurnLeft::TurnLeft(Robot* robot):Behavior(robot) {

}

TurnLeft::~TurnLeft() {
}

bool TurnLeft::startCond(Point* p, Particle* par)
{
	return true;
}

bool TurnLeft::stopCond(Point* p, Particle* par)
{
	if(this->isInfrontWaypoint(p, 4.0, par))
	{
		std::cout << "stop" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void TurnLeft::action()
{
	_robot->setSpeed(0.0, 0.5);
}
