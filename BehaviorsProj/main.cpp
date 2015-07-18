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
int main()
{
	ConfigManager::ReadParameters();

	const char* mapurl = ConfigManager::GetMapUrl().erase(ConfigManager::GetMapUrl().size() - 1).c_str();
	Map* currMap = LoadMap(mapurl);
	currMap->Inflate();
	Grid* grid = new Grid(currMap->GetMatrix(),currMap->GetWidth(),currMap->GetHeight(),ConfigManager::GetGridResolution());




//	Robot robot("localhost",6665);
//	PlnObstacleAvoid plnOA(&robot);
//	Manager manager(&robot, &plnOA);
//	manager.run();

}
