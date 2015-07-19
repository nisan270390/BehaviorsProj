/*
 * Manager.h
 *
 *  Created on: Dec 21, 2014
 *      Author: user
 */

#ifndef MANAGER_H_
#define MANAGER_H_
#include "Plans/PlnObstacleAvoid.h"
#include "Path/WayPoints.h"
#include "Map/Map.h"
#include "Robot.h"
#include "LocalizationManager.h"
#include "Particle.h"
#include <vector>

class Manager
{
public:
	Manager(Robot* robot, Plan* pln, vector<Point *> wPoints, Map* currMap);
	void run();
	virtual ~Manager();

private:
	double CalcDistanceFromRobot(Point* point);
	Behavior* _curr;
	Robot* _robot;
	vector<Point *> _waypointsArr;
	Map* _Map;
	LocalizationManager* _localManger;
};

#endif /* MANAGER_H_ */
