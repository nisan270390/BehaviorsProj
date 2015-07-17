/*
 * PathPlanner.h
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#ifndef PATHPLANNER_H_
#define PATHPLANNER_H_

#include <string.h>
#include <queue>
#include "../Map/Grid.h"
#include "../Configuration/ConfigManager.h"
#include "Node.h"

using namespace std;

class PathPlanner {
public:
	PathPlanner();
	virtual ~PathPlanner();
	string pathFind(int & xStart, int & yStart,
	                int & xFinish, int & yFinish, Grid grid);
};

#endif /* PATHPLANNER_H_ */
