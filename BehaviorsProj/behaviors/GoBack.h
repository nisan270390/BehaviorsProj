

#ifndef GOBACK_H_
#define GOBACK_H_

#include "Behavior.h"

class GoBack: public Behavior {
public:
	GoBack(Robot* robot);
	bool startCond()
	{
		return true;
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
		_robot->setSpeed(0.0, 1.0);
	}
	virtual ~GoBack();
};

#endif /* TURNRIGHT_H_ */
