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

bool Behavior::isInfrontWaypoint(Point* p, double degree, Particle* par)
{
/*	double waypointX = p->GetCol() * CM_TO_METER - _robot->GetXPos();
	double waypointY = p->GetRow() * CM_TO_METER - _robot->GetYPos();
	double degreeToWaypoint = atan2(waypointY, waypointX) * 180 / PI ;

	double difToRotate = abs(degreeToWaypoint) - (_robot->GetYaw() * 180 / PI );

//	cout << "degreeToWaypoint :" << degreeToWaypoint << "         difToRotate :" << difToRotate << "     YAW : " << _robot->GetYaw() << endl;
	cout << "degreeToWaypoint :" << degreeToWaypoint << "(" << _robot->GetXPos() << "," << _robot->GetYPos() << "), Diff: " << difToRotate;
*/
	//double waypointX = _robot->GetXPos() - p->GetCol() * CM_TO_METER;
	//double waypointY = -_robot->GetYPos() - p->GetRow() * CM_TO_METER;

	double waypointX = par->getX() - p->GetCol() * CM_TO_METER;
	double waypointY = -par->getY() - p->GetRow() * CM_TO_METER;
	int degreeToWaypoint = (atan2(waypointY, waypointX) * 180 / PI);
	degreeToWaypoint = 180 - degreeToWaypoint;

	degreeToWaypoint = (degreeToWaypoint + 360) % 360;

	//double difToRotate = degreeToWaypoint - (_robot->GetYaw() * 180 / PI );
	double difToRotate = degreeToWaypoint - (par->getYaw() * 180 / PI );

	/*cout << "degreeToWaypoint :" << degreeToWaypoint << "(" << _robot->GetXPos() << "," << -_robot->GetYPos()<<
				" Curr:" << _robot->GetYaw() * 180 / PI << "), Diff: " << difToRotate <<
				" 	Popint: (" << p->GetCol() * CM_TO_METER << "," << p->GetRow() * CM_TO_METER<< ")" << endl;*/

	cout << "degreeToWaypoint :" << degreeToWaypoint << "(" << par->getX() << "," << -par->getY()<<
					" Curr:" << par->getYaw() * 180 / PI << "), Diff: " << difToRotate <<
					" 	Popint: (" << p->GetCol() * CM_TO_METER << "," << p->GetRow() * CM_TO_METER<< ")" << endl;

	if (-degree <= difToRotate && difToRotate <= degree) {
		return true;
	}
	else {
		return false;
	}
}
