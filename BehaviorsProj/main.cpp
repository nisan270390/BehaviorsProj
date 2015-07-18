/*
 * main.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */
#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"
#include "Configuration/ConfigManager.h" // TODO: REMOVE AFTER TEST
#include "Map/Map.h"
#include "Map/pngUtil.h"
#include "Map/Grid.h"
#include "Map/Point.h"
#include "Path/PathPlanner.h"
#include "Path/WayPoints.h"
#include <vector>
int main()
{
	// Read the configuration file
	ConfigManager::ReadParameters();

	// Read and inflate map
	const char* mapurl = ConfigManager::GetMapUrl().erase(ConfigManager::GetMapUrl().size() - 1).c_str();
	Map* currMap = LoadMap(mapurl);
	Map* inflateMap = currMap->Inflate();

	// Calculate the ratio between the grid resolution and map resolution
	int res = ConfigManager::GetGridResolution() / ConfigManager::GetMapResolution();
	Grid* grid = new Grid(inflateMap->GetMatrix(),inflateMap->GetWidth(),inflateMap->GetHeight(), res);

	// A*
	PathPlanner* p = new PathPlanner();
	Point* start = ConfigManager::GetStartLocationMapResolution();
	Point* end = ConfigManager::GetGoalMapResolution();
	int startGridPointX,startGridPointY, endGridPointX, endGridPointY;
	startGridPointX = start->GetRow() / res;
	startGridPointY = start->GetCol() / res;
	endGridPointX = end->GetRow() / res;
	endGridPointY = end->GetCol() / res;

	std::string route = p->pathFind(startGridPointX ,startGridPointY,endGridPointX,endGridPointY,grid);


	// WayPoint calculation
	Point* startWithRes = new Point(start->GetRow() / 4, start->GetCol() / 4);
	vector<Point *> waypointsArr = WayPoints::CalculateByDirectionalPath(route, startWithRes);


	Robot robot("localhost",6665);
	PlnObstacleAvoid plnOA(&robot);
	Manager manager(&robot, &plnOA, waypointsArr, currMap);
	manager.run();
}
