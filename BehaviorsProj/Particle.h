
#ifndef PARTICLE_H_
#define PARTICLE_H_


#include"Map/Map.h"
#include"Robot.h"
#include "Map/Point.h"
#include "Configuration/Constants.h"
#include <iostream>

using namespace std;

class Particle {
private:
    double _xPos, _yPos, _yaw;
    double _belief;
    Map* _map;

public:
    Particle(double xPos, double yPos, double yaw, double belief);

    void update(double deltaX, double deltaY, double deltaYaw, Robot *rob, Map *wolrdMap);
    Particle* CreateParticle();
    double getX();
    double getY();
    double getYaw();
    void printPosition();
    double getBelief();
    double calcBelief(Robot *rob, Map *wolrdMap);
    virtual ~Particle();
};

#endif /* PARTICLE_H_ */
