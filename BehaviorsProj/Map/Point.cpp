/*
 * Point.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "Point.h"

Point::Point(int row, int col)
{
	this->row = row;
	this->col = col;
}

Point::~Point() {
}

int Point::GetRow()
{
	return this->row;
}

int Point::GetCol()
{
	return this->col;
}

void Point::SetRow(int row)
{
	this->row = row;
}

void Point::SetCol(int col)
{
	this->col = col;
}

/*Point Point::ConvertToRealWorld()
{
	Point newPoint = Point(this->row, this->col);
	int gridResolution = ConfigManager::GetGridResolution();
	newPoint.SetRow(ceil(this->row * gridResolution) + gridResolution / 2);
	newPoint.SetCol(ceil(this->col * gridResolution) + gridResolution / 2);
	return newPoint;
}*/
