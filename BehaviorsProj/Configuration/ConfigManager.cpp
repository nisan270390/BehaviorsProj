/*
 * ConfigManager.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#include "ConfigManager.h"
using namespace std;

string ConfigManager::mapUrl;
int ConfigManager::startLocationX;
int ConfigManager::startLocationY;
int ConfigManager::startLocationYaw;
int ConfigManager::goalX;
int ConfigManager::goalY;
int ConfigManager::robotWidth;
int ConfigManager::robotHeight;
double ConfigManager::mapResolution;
double ConfigManager::gridResolution;

ConfigManager::ConfigManager() {
	// TODO Auto-generated constructor stub

}

ConfigManager::~ConfigManager() {
	// TODO Auto-generated destructor stub
}

void ConfigManager::ReadParameters()
{
	  string line;
	  ifstream myfile ("Configuration/parameters.txt");
	  if (myfile.is_open())
	  {
		  string parameter;
		  string value;
		  string delimiter = ":";
		  int pos;

		  while ( getline (myfile,line) ) {

	    	pos = line.find(delimiter);
	    	parameter = line.substr(0, pos);
	    	value = line.substr(pos + 2, line.length() - pos);

	    	if (parameter == "map")
			{
	    		mapUrl = value;
			}
	    	else if (parameter == "startLocation")
			{
	    		string num;
	    		int index;

	    		index = value.find(" ");
	    		num = value.substr(0, index);
	    		startLocationX = atoi(num.c_str());
	    		index = value.find(" ", index + 1);
	    		num = value.substr(num.length(), index);
	    		startLocationY = atoi(num.c_str());
	    		num = value.substr(index + 1, value.length() - index);
	    		startLocationYaw = atoi(num.c_str());
			}
	    	else if (parameter == "goal")
	    	{
	    		int index;

	    		index = value.find(" ");
	    		goalX = atoi(value.substr(0, index).c_str());
	    		goalY = atoi(value.substr(index + 1, value.length() - index).c_str());
			}
	    	else if (parameter == "robotSize")
			{
	    		int index;

	    		index = value.find(" ");
	    		robotWidth = atoi(value.substr(0, index).c_str());
	    		robotHeight = atoi(value.substr(index + 1, value.length() - index).c_str());
			}
	    	else if (parameter == "MapResolutionCM")
			{
	    		mapResolution = atof(value.c_str());
			}
	    	else if (parameter == "GridResolutionCM")
	    	{
	    		gridResolution = atof(value.c_str());
			}
		  }
	    myfile.close();
	  }

	  else cout << "Unable to open file";
}
