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
	unsigned width, height;
	unsigned x, y;
	//decode
	unsigned error = lodepng::decode(image, width, height, filename);

	//if there's an error, display it
	if (error)
		std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;

	int** map = new int*[width];

	for (x = 0; x < width; x++)
	{
		map[x] = new int[height];
		std::cout << x<< std::endl;
		for (y = 0; y < height; y++)
		{
			if (IsPixelWhite(image, width, height, x, y))
			{
				map[x][y] = 0; // TODO: Change to constant
			}
			else
			{
				map[x][y] = 1; // TODO: Change to constant
			}
		}
	}

	return new Map(width, height, map);
}

bool IsPixelWhite(std::vector<unsigned char> image, int width, int height, int row, int col)
{
	// If enters the condition - there is not absence of color - meaning the cell is white
	return (image[col * width * 4 + row * 4 + 0] ||
			image[col * width * 4 + row * 4 + 1] ||
			image[col * width * 4 + row * 4 + 2]);
}
