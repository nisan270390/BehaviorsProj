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

struct indexNode {
  int index;
  indexNode *next; };

static Point** CalculateByAStarPath(string path, Point* location);
static int* CalculateIndicesOfWayPoints(int* path, int pathLength);
static Point* CalculateLocationByStep(Point* location, int step);
static void AddIndexToList(indexNode* list, int newIndex, int listLength);
static int* ConvertIndexListToArray(indexNode* list, int listLength);
static void ConvertStringToPathArray(string path, int* pathArray);

#endif /* WAYPOINTS_H_ */
