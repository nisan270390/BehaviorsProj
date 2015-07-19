
#ifndef GOFORWARD_H_
#define GOFORWARD_H_

#include "Behavior.h"
#include "../Map/Point.h"
#include "../Particle.h"

class GoForward: public Behavior {
public:
	GoForward(Robot* robot);
	/*bool startCond()
	{
		if(_robot->isFree(245, 402, 0.5) )
			return true;
		else
			return false;
	}
	bool stopCond()
	{
		if(!_robot->isFree(245, 402, 0.5))
					return true;
				else
					return false;
	}

	void action()
	{
		_robot->setSpeed(0.5, 0.0);
	}*/
	bool startCond(Point* p, Particle* par);
	bool stopCond(Point* p, Particle* par);
	void action();
	virtual ~GoForward();
};

#endif /* TURNRIGHT_H_ */
