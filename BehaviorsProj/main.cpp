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
#include "Path/PathPlanner.h"
int main()
{
	ConfigManager::ReadParameters();

	const char* mapurl = ConfigManager::GetMapUrl().erase(ConfigManager::GetMapUrl().size() - 1).c_str();
	Map* currMap = LoadMap(mapurl);
	currMap = currMap->Inflate();
	int res = ConfigManager::GetGridResolution() / ConfigManager::GetMapResolution();
	Grid* grid = new Grid(currMap->GetMatrix(),currMap->GetWidth(),currMap->GetHeight(), res);
	grid->Print();
	PathPlanner* p = new PathPlanner();
	Point* start = ConfigManager::GetStartLocation();
	Point* end = ConfigManager::GetGoal();
	int a,b,c,d;
	a = start->GetRow() / res;
	b = start->GetCol() / res;
	c = end->GetRow() / res;
	d = end->GetCol() / res;
	//string path =
	cout << p->pathFind(a,b,c,d,grid);



//	Robot robot("localhost",6665);
//	PlnObstacleAvoid plnOA(&robot);
//	Manager manager(&robot, &plnOA);
//	manager.run();

}
