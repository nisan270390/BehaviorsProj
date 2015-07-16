/*
 * Map
 *
 *  Created on: Jun 20, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_
#include <libplayerc++/playerc++.h>

class Map{
public :
	Map();
	void UpdateMap();
	bool IsCellEmpty(int x, int y);
	virtual ~Map();
};




#endif /* MAP_ */
