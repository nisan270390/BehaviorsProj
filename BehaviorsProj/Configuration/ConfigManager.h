/*
 * ConfigManager.h
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#ifndef CONFIGMANAGER_H_
#define CONFIGMANAGER_H_

#include <iostream>
#include <fstream>
#include <string.h>

class ConfigManager {
public:
	ConfigManager();
	virtual ~ConfigManager();
	static void ReadParameters();
	static std::string GetMapUrl();
	static int GetStartLocationX();
	static int GetstartLocationY();
	static int GetstartLocationYaw();
	static int GetGoalX();
	static int GetGoalY();
	static int GetRobotWidth();
	static int GetRobotHeight();
	static double GetMapResolution();
	static double GetGridResolution();

private:
	static std::string mapUrl;
	static int startLocationX;
	static int startLocationY;
	static int startLocationYaw;
	static int goalX;
	static int goalY;
	static int robotWidth;
	static int robotHeight;
	static double mapResolution;
	static double gridResolution;
};
#endif /* CONFIGMANAGER_H_ */
