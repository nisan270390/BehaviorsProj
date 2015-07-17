/*
 * WayPoints.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WayPoints.h"

static int** CalculateByAStarPath(int ** mapMatrix, int width, int height,
								  string path, int locationRow, int locationCol)
{
	int** wayPoints;
	int pathLength = path.length();
	int* pathArray = new int[pathLength];

	ConvertStringToPathArray(path, pathArray);

	// Gets all the indexes of the path's way points.
	int* wayPointIndices = CalculateIndicesOfWayPoints(pathArray, pathLength);
	int numberOfPoints = (sizeof(wayPointIndices)/sizeof(*wayPointIndices));
	wayPoints = new int*[numberOfPoints];

	int wayPointCounter = 0;
	int currentWayPointIndex = wayPointIndices[wayPointCounter];

	for (int pathStep = 0; (pathStep < pathLength) && (wayPointCounter != numberOfPoints); pathStep++)
	{
		//TODO : Module to different method when there's a point object - CalculateLocationByStep(int locationRow, int locationCol, int step)
		// Calculates the new location according to the step of the path.
		int step = pathArray[pathStep];

		locationRow += ConfigManager::GetRowDirectionVector()[step];
		locationCol += ConfigManager::GetColDirectionVector()[step];

		// Checks if the current step is a way point.
		if (currentWayPointIndex == pathStep)
		{
			// Adds the way point to the array
			wayPoints[currentWayPointIndex] = new int[2];
			wayPoints[currentWayPointIndex][0] = locationRow;
			wayPoints[currentWayPointIndex][1] = locationCol;

			// Updates counters
			wayPointCounter++;
			currentWayPointIndex = wayPointIndices[wayPointCounter];
		}
	}

	return wayPoints;
}

static void ConvertStringToPathArray(string path, int* pathArray)
{
	for (int index = 0; index < path.length(); index++)
	{
		string temp;
		temp += path[index];
		pathArray[index] = atoi(temp.c_str());
	}
}

static int* CalculateIndicesOfWayPoints(int* path, int pathLength)
{
	int listLength = 0;
	int sequenceLength = 1;
	bool isSequential;
	indexNode* indicesList;
	indexNode* root;

	indicesList = new indexNode;
	indicesList->index = 0;
	indicesList->next = 0;
	root = indicesList;

	for (int index = 1; index < pathLength - 1; index ++)
	{
		isSequential = path[index] == path[index - 1];

		// Checks if the current index continues going the same way as before
		if (isSequential)
		{
			sequenceLength++;
		}

		// Checks whether to add the point to the path - if there's a change of yaw or the sequence is greater than the sequenceLength constant
		if ((!isSequential) || (sequenceLength == 4)) // TODO: constant
		{
			// Adds the index to the list
			AddIndexToList(indicesList, index, listLength);

			// Resets sequence length
			sequenceLength = 1;
		}
	}

	// Adds the last point to the path.
	AddIndexToList(indicesList, pathLength - 1, listLength);

	return ConvertIndexListToArray(indicesList, listLength);
}

static void AddIndexToList(indexNode* list, int newIndex, int listLength)
{
	indexNode* newIndexNode = new indexNode;
	newIndexNode->index = newIndex;
	newIndexNode->next = 0;
	list->next = newIndexNode;
	list = newIndexNode;
	listLength++;
}

static int* ConvertIndexListToArray(indexNode* list, int listLength)
{
	int* array = new int[listLength];

	for (int index = 0; index < listLength; index++)
	{
		array[index] = list->index;
		list = list->next;
	}

	return array;
}
