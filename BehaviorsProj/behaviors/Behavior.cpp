/*
 * Behavior.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#include "Behavior.h"

Behavior::Behavior(Robot* robot) {
	_robot = robot;

}

Behavior::~Behavior() {
	// TODO Auto-generated destructor stub
}

bool Behavior::isInfrontWaypoint(Point* p)
{
	double waypointX = p->GetRow() - _robot->GetXPos();
	double waypointY = p->GetCol() - _robot->GetYPos();
	double degreeToWaypoint = atan2(waypointY, waypointX) * 180 / 3.14159 ;

	double difToRotate = degreeToWaypoint - _robot->GetYaw() * 180 / 3.14159;

	cout << "degreeToWaypoint :" << degreeToWaypoint << "         difToRotate :" << difToRotate << "     YAW : " << _robot->GetYaw() << endl;

	if (-2 <= difToRotate && difToRotate <= 2) {
		return true;
	}
	else {
		return false;
	}
}
