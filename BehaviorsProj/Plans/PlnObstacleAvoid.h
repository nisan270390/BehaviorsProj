/*
 * PlnObstacleAvoid.h
 *
 *  Created on: Dec 21, 2014
 *      Author: user
 */

#ifndef PLNOBSTACLEAVOID_H_
#define PLNOBSTACLEAVOID_H_

#include "Plan.h"
#include "../behaviors/Behavior.h"
#include "../behaviors/GoForward.h"
#include "../behaviors/TurnRight.h"
#include "../behaviors/TurnLeft.h"
#include "../behaviors/GoBack.h"


class PlnObstacleAvoid: public Plan {

		Behavior* _beh[4];

	public:
		PlnObstacleAvoid(Robot* robot);
		Behavior* getStartPoint() {return _start;}
		virtual ~PlnObstacleAvoid();
};

#endif /* PLNOBSTACLEAVOID_H_ */
