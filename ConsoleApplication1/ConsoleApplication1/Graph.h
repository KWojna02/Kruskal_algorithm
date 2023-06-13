#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include<fstream>

class Graph
{
	int size = 0;
public:
	int getSize();
	Edge* getGraph(string filename);
};
#endif GRAPH_H
