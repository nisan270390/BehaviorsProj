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

Point* Point::ConvertResolution(double resolution)
{
	Point* newPoint = new Point(this->row, this->col);
	newPoint->SetRow(ceil(this->row * resolution) + resolution / 2);
	newPoint->SetCol(ceil(this->col * resolution) + resolution / 2);
	return newPoint;
}
