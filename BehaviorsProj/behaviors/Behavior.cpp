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
	double waypointX = p->GetRow();
	double waypointY = p->GetCol();
	double degreeToWaypoint = atan2(waypointY, waypointX) *  180 / 3.14159;

	double difToRotate = degreeToWaypoint - _robot->GetYaw();

	if (-2 <= difToRotate && difToRotate <= 2) {
		return true;
	}
	else {
		return false;
	}
}
