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

	_gridMatrix = new int*[height];

	// Initializing grid's cells
	for (int row = 0; row < height; row++)
	{
		_gridMatrix[row] = new int[width];

		for (int col = 0; col < width; col++)
		{
			// Checks for every cell if the original matrix contained an obstacle.
			_gridMatrix[row][col] = IsMatrixContainObstacle(matrix, matWidth, matHeight, row, col);
		}
	}
}

int Grid::IsMatrixContainObstacle(int** matrix, int matWidth,int matHeight, int row, int col)
{
	int isObstacle = 0;

	int matRow = row * res;
	int matCol = col * res;

	// Running on the matrix - avoid hitting the walls and if found obstacle - break.
	for (int rowIndex = 0; (rowIndex < res && matRow + rowIndex < matHeight && !isObstacle); rowIndex++)
	{
		for (int colIndex = 0; (colIndex < res && matCol + colIndex < matWidth && !isObstacle); colIndex++)
		{
			// Checks if the original matrix contained an obstacle.
			if (matrix[matRow + rowIndex][matCol + colIndex] != 0)
			{
				isObstacle = 1;
			}
		}
	}

	return isObstacle;
}

int Grid::GetHeight()
{
	return this->height;
}

int Grid::GetWidth()
{
	return this->width;
}

int** Grid::GetMatrix()
{
	return this->_gridMatrix;
}


void Grid::Print()
{
	FILE* f = fopen("gridPath.txt", "w");
		if (f == NULL) {
			printf("Error opening file!\n");
			exit(1);
		}

		for (int row = 0; row < height; row++)
		{
			for (int col = 0; col < width; col++)
			{
				fprintf(f, "%d", this->_gridMatrix[row][col]);
			}
			fprintf(f, "\n");
		}

		fclose(f);
}


Grid::~Grid() {
}

