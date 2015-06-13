#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_

#include "Behavior.h"

class TurnLeft: public Behavior {
public:
	TurnLeft(Robot* robot);
	bool startCond()
	{
		if(_robot->isFree(500, 620, 0.5) )
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
		_robot->setSpeed(0.0, -0.3);
	}
	virtual ~TurnLeft();
};

#endif /* TURNRIGHT_H_ */
