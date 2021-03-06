#include "LocalizationManager.h"

LocalizationManager::LocalizationManager(Robot* rob, Map *WolrdMap)
{
	Particle* par = new Particle(ConfigManager::GetStartLocationRealWorldResolution()->GetCol() / 100.0,
			-ConfigManager::GetStartLocationRealWorldResolution()->GetRow() / 100.0,
			 ConfigManager::GetstartLocationYaw()  * PI / 180.0,  1);
	_rob = rob;
	_particles.push_back(par);
	_particles_count = 1;
	_map = WolrdMap;

	for (int i=0; i< PARTICLES_MIN; i++)
	{
		_particles.push_back(par->CreateParticle());
		_particles_count++;
	}
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
	vector<int> parIndexToDelete;

	for (int currParticle = 0; currParticle < _particles_count; currParticle++)
	{
		_particles[currParticle]->update(deltaX, deltaY, deltaYaw, _rob, _map);
		double particleBelief = _particles[currParticle]->getBelief();

		if (particleBelief < MIN_BELIEF)
		{
			parIndexToDelete.push_back(particleBelief);
			//DeleteParticle(currParticle);
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

	for (int i=0; i< parIndexToDelete.size(); i++)
	{
		DeleteParticle(parIndexToDelete[i]);
	}

	if (_particles_count == 0)
	{
		bestParticle = new Particle(_rob->GetXPos(), _rob->GetYPos(), _rob->GetYaw(), 1);
	}

	this->CreateParticle(bestParticle);
	while(_particles_count < PARTICLES_MIN)
	{
		this->CreateParticle(bestParticle);
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
