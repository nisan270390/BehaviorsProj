#ifndef TURNLEFT_H_
#define TURNLEFT_H_

#include "Behavior.h"
#include "../Particle.h"

class TurnLeft: public Behavior {
public:
	TurnLeft(Robot* robot);
	bool startCond(Point* p, Particle* par);
	bool stopCond(Point* p, Particle* par);
	void action();

	/*bool startCond(Point* p, Particle* par)
	{
		if(_robot->isFree(500, 620, 0.5) )
			return true;
		else
			return false;
	}
	bool stopCond(Point* p, Particle* par)
	{
		if(_robot->isFree(245, 402, 0.5))
					return true;
				else
					return false;
	}

	void action()
	{
		_robot->setSpeed(0.0, 0.3);
	}*/
	virtual ~TurnLeft();
};

#endif /* TURNRIGHT_H_ */
