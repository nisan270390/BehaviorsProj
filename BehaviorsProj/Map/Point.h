/*
 * Point.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef POINT_H_
#define POINT_H_
#include "../Configuration/ConfigManager.h"

class Point {
public:
	Point(int row, int col);
	virtual ~Point();
	int GetRow();
	int GetCol();
	void SetRow(int row);
	void SetCol(int col);
	Point ConvertToRealWorld();

private:
	int row;
	int col;
};



#endif /* POINT_H_ */
