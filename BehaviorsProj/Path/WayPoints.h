/*
 * WayPoints.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef WAYPOINTS_H_
#define WAYPOINTS_H_

struct indexNode {
  int index;
  indexNode *next; };

static int** CalculateByAStarPath(int ** mapMatrix, int* directionVector, int* path, int pathLength);
static int* CalculateIndicesOfWayPoints(int* path, int pathLength);
static void AddIndexToList(indexNode* list, int newIndex, int listLength);
static int* ConvertIndexListToArray(indexNode* list, int listLength);

#endif /* WAYPOINTS_H_ */
