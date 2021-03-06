/*
 * Manager.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: user
 */

#include "Manager.h"
Manager::Manager(Robot* robot, Plan* pln, vector<Point *> wPoints, Map* currMap)
{
	_robot = robot;
	_curr = pln->getStartPoint();
	_waypointsArr = wPoints;
	_Map = currMap;
	_localManger = new LocalizationManager(robot, currMap);
}
void Manager::run()
{
	// fix players bugs
	for (int i=0; i < 50; i++)
	{
		_robot->Read();
	}

	// init start point
	_robot->SetOdometry(ConfigManager::GetStartLocationRealWorldResolution()->GetCol() / 100.0,
					-ConfigManager::GetStartLocationRealWorldResolution()->GetRow() / 100.0,
					 ConfigManager::GetstartLocationYaw()  * PI / 180.0);
	_robot->Read();

	int res = ConfigManager::GetGridResolution();
	int currWayPointIndex = 0;

	//Convert All waypoints to map resolution
	for (int j=0; j < this->_waypointsArr.size(); j++)
	{
		this->_waypointsArr[j] = this->_waypointsArr[j]->ConvertResolution(res);
	}

	// Get the next waypoint position
	Point* nextPosition = this->_waypointsArr[currWayPointIndex];

	double XPos = _robot->GetXPos();
	double YPos = -_robot->GetYPos();
	double Yaw = _robot->GetYaw();
	Particle* par = _localManger->getBestParticle();

	// running until we hit the way point
	while (currWayPointIndex != this->_waypointsArr.size())
	{

		// checking whether the current behaviors stop condition fulfills
		while(!(_curr->stopCond(nextPosition, par)))
		{
			// Entered the while meaning the behavior can react - running behavior
			_curr->action();
			// Reading new robot's sensors
			_robot->Read();
			_robot->setSpeed(0.0,0.0);
			double delteXPos = _robot->GetXPos() - XPos;
			double delteYPos = -_robot->GetYPos() - YPos;
			double delteYaw = _robot->GetYaw() - Yaw;
			_localManger->update(delteXPos, delteYPos, delteYaw);

			XPos = _robot->GetXPos();
			YPos = -_robot->GetYPos();
			Yaw = _robot->GetYaw();

			par = _localManger->getBestParticle();

			//cout << "(" << _robot->GetXPos() << "," << _robot->GetYPos() << " Yaw: " << _robot->GetYaw() << " D: ";
			//cout << this->CalcDistanceFromRobot(nextPosition) << endl;

			// Checking whether we're close enough to the waypoint.
			if (this->CalcDistanceFromRobot(nextPosition) < DISTANCE_FROM_WAYPOINT * CM_TO_METER)
			{
				currWayPointIndex++;
				nextPosition = this->_waypointsArr[currWayPointIndex];
			}
		}

		_robot->setSpeed(0.0, 0.0);
		_curr = _curr->selectNext(nextPosition, par);
		_robot->Read();

	}

	/*if(!(_curr->startCond()))
		_curr = _curr->selectNext();
	_curr->action();
	while(_curr !=NULL)
	{
		while(_curr->stopCond() == false)
		{
			_curr->action();
			_robot->Read();
		}
		_curr = _curr->selectNext();
		_robot->Read();
	}*/


}

double Manager::CalcDistanceFromRobot(Point* point)
{
	//double xRobot = this->_robot->GetXPos();
	//double yRobot = -this->_robot->GetYPos();

	Particle* par = _localManger->getBestParticle();
	double xRobot = par->getX();
	double yRobot = -par->getY();


	//Point* p = point->ConvertResolution(ConfigManager::GetMapResolution());
	double xPoint =	point->GetCol() * CM_TO_METER;
	double yPoint =	point->GetRow() * CM_TO_METER;

	double xDistance = xRobot - xPoint;
	double yDistance = yRobot - yPoint;

	return sqrt(xDistance*xDistance + yDistance*yDistance);

}

Manager::~Manager() {
}
