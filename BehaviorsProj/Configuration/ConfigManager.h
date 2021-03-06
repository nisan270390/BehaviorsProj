/*
 * ConfigManager.h
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#ifndef CONFIGMANAGER_H_
#define CONFIGMANAGER_H_
#define DIRECTION_VECTOR_SIZE 8

#include <iostream>
#include <fstream>
#include <string.h>
#include "../Map/Point.h"

class Point;

class ConfigManager {
public:
	ConfigManager();
	virtual ~ConfigManager();
	static void ReadParameters();
	static std::string GetMapUrl();
	static Point* GetStartLocationMapResolution();
	static Point* GetStartLocationRealWorldResolution();
	static int GetstartLocationYaw();
	static Point* GetGoalMapResolution();
	static Point* GetGoalRealWorldResolution();
	static int GetRobotWidth();
	static int GetRobotHeight();
	static double GetMapResolution();
	static double GetGridResolution();
	static int* GetRowDirectionVector();
	static int* GetColDirectionVector();

private:
	static std::string mapUrl;
	static Point* startLocation;
	static int startLocationYaw;
	static Point* goal;
	static int robotWidth;
	static int robotHeight;
	static double mapResolution;
	static double gridResolution;
	static int rowDirectionVector[];
	static int colDirectionVector[];

};
#endif /* CONFIGMANAGER_H_ */
