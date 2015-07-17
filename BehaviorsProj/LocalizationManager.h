
#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include "Particle.h"
#include <vector>
#include "Robot.h"
#include "Map/Map.h"
#include "/Configuration/ConfigManager.h"

class LocalizationManager {
private:
    vector<Particle *> _particles;
    Robot* _rob;
    int _particles_count;
    Map* _map;

public:
    LocalizationManager(Robot* rob, Map *WolrdMap);

    void update(double deltaX, double deltaY, double deltaYaw);
    bool CreateParticle(Particle* par);
	void DeleteParticle(int index);
    Particle *getBestParticle();
    void PrintParticles();

    virtual ~LocalizationManager();
};


#endif /* LOCALIZATIONMANAGER_H_ */
