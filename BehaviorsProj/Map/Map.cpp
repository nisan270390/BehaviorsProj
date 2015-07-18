/*
 * Map.cpp
 *
 *  Created on: Jun 20, 2015
 *      Author: colman
 */

#include "Map.h"

Map::Map(int width, int height, int** map)
{
	this->_map = map;
	this->width = width;
	this->height = height;
}

Map::~Map()
{
	// TODO
}

Map* Map::Inflate()
{
	int robotSize = MAX(ConfigManager::GetRobotHeight(),ConfigManager::GetRobotWidth());
	double mapResulotion = ConfigManager::GetMapResolution();
	int InflateAddition = ceil((robotSize / 2) / mapResulotion);

	int** inflatedMap = new int*[width];

	for (int row = 0; row < width; row++)
	{
		inflatedMap[row] = new int[height];

		for (int col = 0; col < height; col++)
		{
			if (_map[row][col] == 0) //TODO: constant
			{
				inflatedMap[row][col] = 0;
			}
			//Case we need to inflate a cell
			else
			{
				for (int infRow = row - InflateAddition; infRow < row + InflateAddition; infRow++)
				{
					for (int infCol = col - InflateAddition; infCol < col + InflateAddition; infCol++)
					{
						if ((infRow > 0 && infRow < width) &&
							(infCol > 0 && infCol < height))
						{
							inflatedMap[infRow][infCol] = 1; //TODO: const
						}
					}
				}
			}
		}
	}

	return new Map(width, height, inflatedMap);
}

bool Map::IsCellEmpty(Point* point)
{
	if (_map[point->GetRow()][point->GetCol()] == 0)
	{
		return true;
	}

	return false;
}

int Map::GetHeight()
{
	return this->height;
}

int Map::GetWidth()
{
	return this->width;
}

int** Map::GetMatrix()
{
	return this->_map;
}
