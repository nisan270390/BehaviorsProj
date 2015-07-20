/*
 * Map
 *
 *  Created on: Jun 20, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_
#include <libplayerc++/playerc++.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include "../Configuration/ConfigManager.h"
#include "../Configuration/Constants.h"

using namespace std;
class Map{
public :
	Map(int width, int height, int** map);
	Map* Inflate(int InflateAddition);
	bool IsCellEmpty(Point* point);
	int GetWidth();
	int GetHeight();
	int** GetMatrix();
	void Print();
	virtual ~Map();

private:
	int width;
	int height;
	int** _map;
};




#endif /* MAP_ */
