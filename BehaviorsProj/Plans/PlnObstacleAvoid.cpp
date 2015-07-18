/*
 * PlnObstacleAvoid.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: user
 */

#include "PlnObstacleAvoid.h"

PlnObstacleAvoid::PlnObstacleAvoid(Robot* robot):Plan(robot) {
	//Creating Behaviors
	_beh[0] = new GoForward(robot);
	_beh[1] = new TurnRight(robot);
	_beh[2] = new TurnLeft(robot);
	_beh[3] = new GoBack(robot);
	Behavior b = new GoForward(robot);


	//Connecting behaviors
	_beh[0]->addBeh(_beh[1]);
	_beh[0]->addBeh(_beh[2]);
	_beh[0]->addBeh(_beh[3]);

	_beh[1]->addBeh(_beh[0]);
	_beh[1]->addBeh(_beh[2]);

	_beh[2]->addBeh(_beh[0]);
	_beh[2]->addBeh(_beh[1]);

	_beh[3]->addBeh(_beh[0]);
	_beh[3]->addBeh(_beh[1]);
	_beh[3]->addBeh(_beh[2]);
	_beh[3]->addBeh(_beh[3]);

	_start = _beh[0];
}

PlnObstacleAvoid::~PlnObstacleAvoid() {
	// TODO Auto-generated destructor stub
	for(int i=0;i<4;i++)
		delete _beh[i];
}
