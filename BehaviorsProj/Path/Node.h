/*
 * Node.h
 *
 *  Created on: Jul 17, 2015
 *      Author: colman
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node(int xp, int yp, int d, int p);
	virtual ~Node();
	int getxPos() const;
	int getyPos() const;
    int getLevel() const;
    int getPriority() const;
    void updatePriority(int & xDest, int & yDest);
    void nextLevel(int & i);
    int & estimate(int & xDest, int & yDest);
    inline bool operator<(const Node & a) const
    {
    	return this->getPriority() > a.getPriority();
    }

private:

    int xPos;
    int yPos;
    int level; // G(N): distance from start point
    int priority;  // F(N): Sum of level and distance from node to target.
};

#endif /* NODE_H_ */
