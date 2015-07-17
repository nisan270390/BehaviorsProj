/*
 * PathPlanner.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: colman
 */

#include "PathPlanner.h"

PathPlanner::PathPlanner() {
	// TODO Auto-generated constructor stub

}

PathPlanner::~PathPlanner() {
	// TODO Auto-generated destructor stub
}

string pathFind(int & xStart, int & yStart,
	                int & xFinish, int & yFinish, Grid grid)
{
	int width = grid.GetWidth();
	int height = grid.GetHeight();

	int closed_nodes_map[width][height]; // map of closed (tried-out) nodes
	int open_nodes_map[width][height]; // map of open (not-yet-tried) nodes
	int dir_map[width][height]; // map of directions
	int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
	int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};
	int** map = grid.GetMatrix();

	priority_queue<Node> pq[2]; // list of open (not-yet-tried) nodes
	int pqi; // pq index
	Node* n0;
	Node* m0;
	int i, j, x, y, xdx, ydy;
	char c;
	pqi=0;

	// reset the node maps
	for(y=0;y<height;y++)
	{
		for(x=0;x<width;x++)
		{
			closed_nodes_map[x][y]=0;
			open_nodes_map[x][y]=0;
		}
	}

	// create the start node and push into list of open nodes
	n0=new Node(xStart, yStart, 0, 0);
	n0->updatePriority(xFinish, yFinish); // CALC f function
	pq[pqi].push(*n0);
	open_nodes_map[x][y]=n0->getPriority(); // mark it on the open nodes map

	// A* search
	while(!pq[pqi].empty())
	{
		// get the current node with the highest priority
		// from the list of open nodes
		n0=new Node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
					 pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

		x=n0->getxPos();
		y=n0->getyPos();

		pq[pqi].pop(); // remove the node from the open list
		open_nodes_map[x][y]=0;
		// mark it on the closed nodes map
		closed_nodes_map[x][y]=1;

		// quit searching when the goal state is reached
		//if((*n0).estimate(xFinish, yFinish) == 0)
		if(x==xFinish && y==yFinish)
		{
			// generate the path from finish to start
			// by following the directions
			string path="";
			while(!(x==xStart && y==yStart))
			{
				j=dir_map[x][y];
				c='0'+(j+dir/2)%dir;
				path=c+path;
				x+=dx[j];
				y+=dy[j];
			}

			// garbage collection
			delete n0;
			// empty the leftover nodes
			while(!pq[pqi].empty()) pq[pqi].pop();
			return path;
		}

		// generate moves (child nodes) in all possible directions
		for(i=0;i<dir;i++)
		{
			xdx=x+dx[i]; ydy=y+dy[i];

			if(!(xdx<0 || xdx>width-1 || ydy<0 || ydy>height-1 || map[xdx][ydy]==1
				|| closed_nodes_map[xdx][ydy]==1))
			{
				// generate a child node
				m0=new Node( xdx, ydy, n0->getLevel(),
							 n0->getPriority());
				m0->nextLevel(i);
				m0->updatePriority(xFinish, yFinish);

				// if it is not in the open list then add into that
				if(open_nodes_map[xdx][ydy]==0)
				{
					open_nodes_map[xdx][ydy]=m0->getPriority();
					pq[pqi].push(*m0);
					// mark its parent node direction
					dir_map[xdx][ydy]=(i+dir/2)%dir;
				}
				// update node priority if we find better path to get this node with less priority
				else if(open_nodes_map[xdx][ydy]>m0->getPriority())
				{
					// update the priority info
					open_nodes_map[xdx][ydy]=m0->getPriority();
					// update the parent direction info
					dir_map[xdx][ydy]=(i+dir/2)%dir;

					// replace the node
					// by emptying one pq to the other one
					// except the node to be replaced will be ignored
					// and the new node will be pushed in instead
					while(!(pq[pqi].top().getxPos()==xdx &&
						   pq[pqi].top().getyPos()==ydy))
					{
						pq[1-pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pq[pqi].pop(); // remove the wanted node

					// empty the larger size pq to the smaller one
					if(pq[pqi].size()>pq[1-pqi].size())
					{
						pqi=1-pqi;
					}

					while(!pq[pqi].empty())
					{
						pq[1-pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pqi=1-pqi;
					pq[pqi].push(*m0); // add the better node instead
				}
				else delete m0; // garbage collection
			}
		}
		delete n0; // garbage collection
	}
	return ""; // no route found
}

