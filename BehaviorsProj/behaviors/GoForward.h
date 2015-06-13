
#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "Behavior.h"

class GoForward: public Behavior {
public:
	GoForward(Robot* robot);
	bool startCond()
	{
		if(_robot->isFree(245, 402, 0.5) )
			return true;
		else
			return false;
	}
	bool stopCond()
	{
		if(_robot->isFree(245, 402, 0.5))
					return true;
				else
					return false;
	}

	void action()
	{
		_robot->setSpeed(0.5, 0.0);
	}
	virtual ~GoForward();
};

#endif /* TURNRIGHT_H_ */
