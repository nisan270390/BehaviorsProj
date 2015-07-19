/*
 * pngUtil.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: colman
 */
#include "pngUtil.h"
#include "lodepng.h"
#include <iostream>


//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, std::vector<unsigned char> image,
		unsigned width, unsigned height) {
	//Encode the image
	unsigned error = lodepng::encode(filename, image, width, height);

	//if there's an error, display it
	if (error)
		std::cout << "encoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;
}

void decodeOneStep(const char* filename) {
	std::vector<unsigned char> image; //the raw pixels
	unsigned width, height;

	//decode
	unsigned error = lodepng::decode(image, width, height, filename);

	//if there's an error, display it
	if (error)
		std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;

	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}

Map* LoadMap(const char* filename) {
	std::vector<unsigned char> image; //the raw pixels
	unsigned height, width;
	unsigned error = lodepng::decode(image, width, height, filename);

	//if there's an error, display it
	if (error)
		std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;

	int** map = new int*[height];

	for (int row = 0; row < height; row++)
	{
		map[row] = new int[width];
		std::cout << row << std::endl;
		for (int col = 0; col < width; col++)
		{
			// If enters the condition - there is not absence of color - meaning the cell is white
			if ((image[row * width * 4 + col * 4 + 0] ||
				 image[row * width * 4 + col * 4 + 1] ||
				 image[row * width * 4 + col * 4 + 2]))
			{
				map[row][col] = FREE_CELL;
			}
			else
			{
				map[row][col] = OBSTACLE_CELL;
			}
		}
	}

	return new Map(width, height, map);
}
