/*
 * pngUtil.h
 *
 *  Created on: Mar 30, 2015
 *      Author: colman
 */

#ifndef PNGUTIL_H_
#define PNGUTIL_H_
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "../Configuration/ConfigManager.h"
#include "Map.h"

void encodeOneStep(const char* filename, std::vector<unsigned char> image, unsigned width, unsigned height);
void decodeOneStep(const char* filename);
Map* LoadMap(const char* filename);
bool IsPixelWhite(std::vector<unsigned char> image, int width, int height, int row, int col);



#endif /* PNGUTIL_H_ */
