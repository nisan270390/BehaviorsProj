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
void LoadMap(const char* filename) {
	std::vector<unsigned char> image; //the raw pixels
	unsigned width, height;
	unsigned x, y;
	//decode
	unsigned error = lodepng::decode(image, width, height, filename);

	//if there's an error, display it
	if (error)
		std::cout << "decoder error " << error << ": "
				<< lodepng_error_text(error) << std::endl;

	int map[width][height];

	for (x = 0; x < width; x++) {
		for (y = 0; y < height; y++){
			// If enters the condition - meaning the cell is white - the map is empty at that point
			if (image[y * width * 4 + x * 4 + 0]
					|| image[y * width * 4 + x * 4 + 1]
					|| image[y * width * 4 + x * 4 + 2])
				map[x][y] = 0; // TODO: Change to constant
			else
				map[x][y] = 1; // TODO: Change to constant
		}
	}

	int robotSize = MAX(ConfigManager::GetRobotHeight(),ConfigManager::GetRobotWidth());
	double mapResulotion = ConfigManager::GetMapResolution();
	int InflateAddition = ceil((robotSize / 2) / mapResulotion);

	int inflatedMap[width][height];

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (map[i][j] == 0) //TODO: constant
			{
				inflatedMap[i][j] = 0;
			}
			//Case we need to inflate a cell
			else
			{
				for (int infI = i - InflateAddition; infI < i + InflateAddition; infI++)
				{
					for (int infJ = j - InflateAddition; infJ < j + InflateAddition; infJ++)
					{
						if (infI > 0 && infI < width && infJ > 0 && infJ < height)
						{
							inflatedMap[infI][infJ] = 1; //TODO: const
						}
					}
				}
			}
		}
	}


}
