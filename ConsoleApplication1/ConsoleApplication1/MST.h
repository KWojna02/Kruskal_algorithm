#ifndef MST_H
#define MST_H

#include "Edge.h"
#include<string>

class MST
{
	int size = 0, weight = 0, time = 0;
	Edge* result= nullptr;

public:
	MST();
	MST(int s, int w, int t, Edge* r);
	int get_w();
	int get_t();
	Edge* get_r();
	string toString(bool printMSTEdges);
};
#endif MST_H
