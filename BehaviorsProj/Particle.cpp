#define RAW 2.0

#include "Particle.h"

Particle::Particle(double xPos, double yPos, double yaw, double belief) {
	// TODO Auto-generated constructor stub
	_xPos = xPos;
	_yPos = yPos;
	_yaw = yaw;
	_belief = belief;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(double deltaX, double deltaY, double deltaYaw, Robot *rob, Map *wolrdMap)
{
	_xPos += deltaX;
	_yPos += deltaY;
	_yaw += deltaYaw;

	_belief = RAW * _belief * calcBelief(rob, wolrdMap);

	// Check to see if particle exceeded the maximum probability
	if (_particleBelief > 1)
	{
		_particleBelief = 1;
	}
}

double Particle::calcBelief(Robot *rob, Map *wolrdMap)
{
	double trueMatch = 0;
	double falseMatch = 0;
	double obstacleX;
	double obstacleY;

	for (int currlaser = 0; currlaser < 666; currlaser+=10)
	{
		double laserAngle = (((currlaser) * (0.36) - 120.0) / 180.0) * 3.14159;
		double distance = rob->getLaserDistance(currlaser);

		obstacleX = distance * cos(_yaw + laserAngle) + _xPos;
		obstacleY = distance * sin(_yaw + laserAngle) + _yPos;

		bool currCellIsEmpty = wolrdMap->IsCellEmpty(obstacleX, obstacleY);

		if (distance < 4.0)
		{
			if (currCellIsEmpty == true)
			{
				falseMatch++;
			}
			else
			{
				trueMatch++;
			}
		}
	}

	return trueMatch / (trueMatch + falseMatch);
}

Particle* Particle::CreateParticle()
{
	double newX = _xPos + (rand() % 21) / 100;
	double newY = _yPos + (rand() % 21) / 100;
	double newYaw = _yaw + (rand() % 61 - 30.0) * 3.14159 / 180.0;
	return new Particle(newX, newY, newYaw, _belief);
}

double Particle::getBelief()
{
	return _belief;
}

double Particle::getX()
{
	return _xPos;
}

double Particle::getY()
{
	return _yPos;
}

double Particle::getYaw()
{
	return _yaw;
}

void Particle::printPosition()
{
	cout<<"x: "<<_xPos<<" y: "<<_yPos<<endl;
}
