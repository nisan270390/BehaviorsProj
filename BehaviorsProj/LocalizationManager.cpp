#define MIN_BELIEF 0.2
#define PARTICLES_MIN 30
#define PARTICLES_MAX 100

#include "LocalizationManager.h"

LocalizationManager::LocalizationManager(Robot* rob, Map *WolrdMap)
{
	_rob = rob;
	_particles.push_back(new Particle(0, 0, 0, 1));
	_particles_count = 1;
	_map = WolrdMap;
}

LocalizationManager::~LocalizationManager()
{
	for(vector<Particle *>::iterator it = _particles.begin(); it!= _particles.end(); it++)
	{
		if ((*it) != NULL)
		{
			delete (*it);
			_particles_count--;
		}
	}
}

void LocalizationManager::update(double deltaX, double deltaY, double deltaYaw)
{
	double maxBelief = 0;
	Particle* bestParticle = NULL;

	for (int currParticle = 0; currParticle < _particles_count; currParticle++)
	{
		_particles[currParticle]->update(deltaX, deltaY, deltaYaw, _rob, _map);

		double particleBelief = _particles[currParticle]->getBelief();

		if (particleBelief < MIN_BELIEF)
		{
			DeleteParticle(currParticle);
		}
		else
		{
			if (maxBelief < particleBelief)
			{
				maxBelief = particleBelief;
				bestParticle = _particles[currParticle];
			}
		}
	}

	if (_particles_count < PARTICLES_MIN)
	{
		this->CreateParticle(bestParticle->CreateParticle());
	}
}

bool LocalizationManager::CreateParticle(Particle* par)
{
	if (_particles_count < PARTICLES_MAX)
	{
		_particles.push_back(par);
		_particles_count++;
		return true;
	}
	else
	{
		return false;
	}
}

void LocalizationManager::DeleteParticle(int index)
{
	_particles.erase(_particles.begin() + index - 1);
	_particles_count--;
}

Particle* LocalizationManager::getBestParticle()
{
	double max = -1;
	int particleNum=-1;
	int i=0;
	for(vector<Particle *>::iterator it = _particles.begin(); it!= _particles.end(); it++)
	{
		if(max <(*it)->getBelief())
		{
			max =(*it)->getBelief();
			particleNum = i;
		}
		i++;
	}
	if(particleNum!=-1)
		return _particles[particleNum];
	return NULL;
}

void LocalizationManager::PrintParticles()
{
	for(vector<Particle *>::iterator it = _particles.begin(); it!= _particles.end(); it++)
	{
		(*it)->printPosition();
	}
}
