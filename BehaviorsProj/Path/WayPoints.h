/*
 * WayPoints.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTS_H_
#define WAYPOINTS_H_
#include "../Configuration/ConfigManager.h"
using namespace std;
#include <string.h>
#include <vector>

class WayPoints
{
public:
	static vector<Point *> CalculateByDirectionalPath(std::string path, Point* location);

private:
	static vector<int> CalculateIndicesOfWayPoints(int* path, int pathLength);
	static Point* CalculateLocationByStep(Point* location, int step);
	static void ConvertStringToPathArray(std::string path, int* pathArray);
};

#endif /* WAYPOINTS_H_ */
