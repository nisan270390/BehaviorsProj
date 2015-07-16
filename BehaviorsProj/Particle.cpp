#define PERC 0.5

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

void Particle::update(double deltaX, double deltaY, double deltaYaw, Robot *rob)
{
	_xPos += deltaX;
	_yPos += deltaY;
	_yaw += deltaYaw;

	_belief=(PERC*calcBelief())+((1-PERC)*_belief);
}

double Particle::calcBelief()
{

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
