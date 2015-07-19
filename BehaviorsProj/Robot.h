/*
 * Robot.h
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#ifndef ROBOT_H_
#define ROBOT_H_
#include "Configuration/Constants.h"
#include <libplayerc++/playerc++.h>

using namespace PlayerCc;

class Robot {
	PlayerClient* _pc;
	Position2dProxy* _pp;
	LaserProxy* _lp;
public:
	Robot(char* ip, int port);
	void Read() {
		_pc->Read();
	}
	void setSpeed(float xSpeed, float angularSpeed) {
		_pp->SetSpeed(xSpeed, angularSpeed);
	}
	bool isRightFree() {
		if ((*_lp)[LASER_RIGHT_INDEX] > LASER_MIN_DISTANCE)
			return true;
		else
			return false;
	}
	bool isForwardFree() {
		if ((*_lp)[LASER_FORWARD_INDEX] > LASER_MIN_DISTANCE)
			return true;
		else
			return false;
	}

	bool isFree(int startIndex, int endIndex, float distance);
	double getLaserDistance(double index);

	double GetXPos();
	double GetYPos();
	double GetYaw();
	void SetOdometry(double xPos, double yPos, double Yaw);
	void SetSpeed(double angel, double speed);




	virtual ~Robot();
};

#endif /* ROBOT_H_ */
