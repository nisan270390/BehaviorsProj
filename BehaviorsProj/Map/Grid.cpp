/*
 * Grid.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#include "Grid.h"

Grid::Grid(int** matrix, int matWidth,int matHeight, double resolution) {
	res = ceil(resolution);
	width = ceil(matWidth / res);
	height = ceil(matHeight / res);

	_gridMatrix = new int*[width];

	// Initializing grid's cells
	for (int row = 0; row < width; row++)
	{
		_gridMatrix[row] = new int[height];

		for (int col = 0; col < height; col++)
		{
			// Checks for every cell if the original matrix contained an obstacle.
			_gridMatrix[row][col] = IsMatrixContainObstacle(matrix, matWidth, matHeight, row, col);
		}
	}
}

int Grid::IsMatrixContainObstacle(int** matrix, int matWidth,int matHeight, int row, int col)
{
	int isObstacle = 0;

	// Running on the matrix - avoid hitting the walls and if found obstacle - break.
	for (int matRow = row; (matRow < res && matRow < matWidth && !isObstacle); matRow++)
	{
		for (int matCol = col; (matCol < res && matCol < matHeight && !isObstacle); matCol++)
		{
			// Checks if the original matrix contained an obstacle.
			if (matrix[row][col] != 0)
			{
				isObstacle = 1;
			}
		}
	}

	return isObstacle;
}

Grid::~Grid() {
	// TODO Auto-generated destructor stub
}

