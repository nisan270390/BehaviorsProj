/*
 * WayPoints.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "WayPoints.h"
using namespace std;

vector<Point *> WayPoints::CalculateByDirectionalPath(std::string path, Point* location)
{
	vector<Point *> wayPoints;
	int pathLength = path.length();
	int* pathArray = new int[pathLength];
	int numberOfPoints = 0;

	ConvertStringToPathArray(path, pathArray);

	// Gets all the indexes of the path's way points.
	vector<int> wayPointIndices = CalculateIndicesOfWayPoints(pathArray, pathLength);

	int wayPointCounter = 0;
	int currentWayPointIndex = wayPointIndices[wayPointCounter];
	Point* newLocation = location;

	for (int pathStep = 0; pathStep < pathLength; pathStep++)
	{
		newLocation = CalculateLocationByStep(newLocation, pathArray[pathStep]);

		// Checks if the current step is a way point.
		if (currentWayPointIndex == pathStep)
		{
			// Adds the way point to the array
			wayPoints.push_back(newLocation);

			// Updates counters
			wayPointCounter++;
			currentWayPointIndex = wayPointIndices[wayPointCounter];
		}
	}

	return wayPoints;
}

void WayPoints::ConvertStringToPathArray(std::string path, int* pathArray)
{
	for (int index = 0; index < path.length(); index++)
	{
		string temp;
		temp += path[index];
		pathArray[index] = atoi(temp.c_str());
	}
}

vector<int> WayPoints::CalculateIndicesOfWayPoints(int* path, int pathLength)
{
	vector<int> indices;
	int sequenceLength = 1;
	bool isSequential;

	for (int index = 1; index < pathLength - 1; index ++)
	{
		isSequential = path[index] == path[index - 1];

		// Checks if the current index continues going the same way as before
		if (isSequential)
		{
			sequenceLength++;
		}

		// Checks whether to add the point to the path - if there's a change of yaw or the sequence is greater than the sequenceLength constant
		if ((!isSequential) || (sequenceLength == MAX_SEQUENCE_LENGTH))
		{
			// Adds the index to the list
			indices.push_back(index - 1);

			// Resets sequence length
			sequenceLength = 1;
		}
	}

	// Adds the last point to the path.
	indices.push_back(pathLength - 1);

	return indices;
}

Point* WayPoints::CalculateLocationByStep(Point* location, int step)
{
	return new Point(ConfigManager::GetRowDirectionVector()[step] + location->GetRow(),
					 ConfigManager::GetColDirectionVector()[step] + location->GetCol());
}
