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

static int** CalculateByAStarPath(int ** mapMatrix, int width, int height, string path, int locationRow, int locationCol);
static int* CalculateIndicesOfWayPoints(int* path, int pathLength);
static void AddIndexToList(indexNode* list, int newIndex, int listLength);
static int* ConvertIndexListToArray(indexNode* list, int listLength);
static void ConvertStringToPathArray(string path, int* pathArray);

#endif /* WAYPOINTS_H_ */
