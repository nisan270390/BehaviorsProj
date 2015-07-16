
#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include "Particle.h"
#include <vector>
#include "Robot.h"
//#include "Map.h"

class LocalizationManager {
private:
    vector<Particle *> _particles;
    Robot* _rob;
    int _particles_count;

public:
    LocalizationManager(Robot* rob);

    void update(double deltaX, double deltaY, double deltaYaw);
    bool CreateParticle(Particle* par);
	void DeleteParticle(int index);
    Particle *getBestParticle();
    void PrintParticles();

    virtual ~LocalizationManager();
};


#endif /* LOCALIZATIONMANAGER_H_ */
