/*
 * Grid.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef GRID_H_
#define GRID_H_

class Grid {
public:
	Grid(int** matrix, int matWidth,int matHeight, int resolution);
	virtual ~Grid();
	int GetHeight();
	int GetWidth();

private:
	int width;
	int height;
	int** _gridMatrix;
};

#endif /* GRID_H_ */
