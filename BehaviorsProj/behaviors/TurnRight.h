/*
 * TurnRight.h
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "Behavior.h"
#include "../Particle.h"

class TurnRight: public Behavior {
public:
	TurnRight(Robot* robot);
	bool startCond(Point* p,  Particle* par)
	{
		if(_robot->isFree(40, 200, 0.5) )
			return true;
		else
			return false;
	}
	bool stopCond(Point* p,  Particle* par)
	{
		if(_robot->isFree(245, 402, 0.5))
					return true;
				else
					return false;
	}

	void action()
	{
		_robot->setSpeed(0.0, -0.3);
	}
	virtual ~TurnRight();
};

#endif /* TURNRIGHT_H_ */
