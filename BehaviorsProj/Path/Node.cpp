/*
 * Node.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */
#include "../Configuration/ConfigManager.h"
#include "Node.h"
#include <math.h>

Node::Node(int xp, int yp, int d, int p) {
	xPos = xp;
	yPos = yp;
	level = d;
	priority = p;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

int Node::getxPos() const
{
	return xPos;
}
int Node::getyPos() const
{
	return yPos;
}
int Node::getLevel() const
{
	return level;
}
int Node::getPriority() const
{
	return priority;
}
void Node::updatePriority(int & xDest, int & yDest)
{
	priority = level+estimate(xDest, yDest)*10; // Calc F(n)
}
void Node::nextLevel(int & i)
{
	level += (DIRECTION_VECTOR_SIZE==8?(i%2==0?10:14):10); //Calc G(n)
}
int & Node::estimate(int & xDest, int & yDest)
{
	static int xd, yd, distance;
	xd=xDest-xPos;
	yd=yDest-yPos;

	// Pitaguras
	distance=static_cast<int>(sqrt(xd*xd+yd*yd));

	return(distance);
}
