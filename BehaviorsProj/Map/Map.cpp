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

	int** inflatedMap = new int*[height];

	// Init array
	// TODO : change this
	for (int row = 0; row < height; row++)
	{
		inflatedMap[row] = new int[width];
	}

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (_map[row][col] == FREE_CELL)
			{
				inflatedMap[row][col] = FREE_CELL;
			}
			//Case we need to inflate a cell
			else
			{
				for (int infRow = row - InflateAddition; infRow < row + InflateAddition; infRow++)
				{
					for (int infCol = col - InflateAddition; infCol < col + InflateAddition; infCol++)
					{
						if ((infRow > 0 && infRow < height) &&
							(infCol > 0 && infCol < width))
						{
							inflatedMap[infRow][infCol] = OBSTACLE_CELL;
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
	if (_map[point->GetRow()][point->GetCol()] == FREE_CELL)
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

void Map::Print()
{
	FILE* f = fopen("mapPath.txt", "w");
		if (f == NULL) {
			printf("Error opening file!\n");
			exit(1);
		}

		for (int row = 0; row < height; row++)
		{
			for (int col = 0; col < width; col++)
			{
				fprintf(f, "%d", this->_map[row][col]);
			}
			fprintf(f, "\n");
		}

		fclose(f);
}
