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
	//_waypointsArr = wPoints;
	_Map = currMap;
}
void Manager::run()
{
	for (int i=0; i < 50; i++)
	{
		_robot->Read();
	}
	int res = ConfigManager::GetGridResolution() / ConfigManager::GetMapResolution();
	int currWayPoint = 0;

	//Convert All waypoints to map resolution
	for (int j=0; j < this->_waypointsArr.size(); j++)
	{
		this->_waypointsArr[j] = this->_waypointsArr[j]->ConvertResolution(res);
	}

	// Get the first position of the robot (the start position)
	Point* currentPosition = this->_waypointsArr[currWayPoint];

	// Get the next waypoint position
	currWayPoint++;
	Point* nextPosition = this->_waypointsArr[currWayPoint];

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
	double xRobot = this->_robot->GetXPos();
	double yRobot = this->_robot->GetYPos();

	Point* p = point->ConvertResolution(ConfigManager::GetMapResolution());
	double xPoint =	p->GetCol();
	double yPoint =	p->GetRow();

	double xDistance = xRobot - xPoint;
	double yDistance = yRobot - yPoint;

	return sqrt(xDistance*xDistance + yDistance*yDistance);

}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}
