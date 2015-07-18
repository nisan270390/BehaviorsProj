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
	Grid(int** matrix, int matWidth,int matHeight, double resolution);
	virtual ~Grid();
	int GetHeight();
	int GetWidth();
	void Print();
	int** GetMatrix();

private:
	int IsMatrixContainObstacle(int** matrix, int matWidth,int matHeight, int row, int col);
	int width;
	int height;
	int res;
	int** _gridMatrix;
};

#endif /* GRID_H_ */
