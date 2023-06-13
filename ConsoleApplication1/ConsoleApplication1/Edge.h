#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <string>

using namespace std;

class Edge
{
	int source = NULL;
	int destination = NULL;
	int weight = NULL;

public:
	Edge();
	Edge(int s, int d, int w);
	void set_s(int s);
	int get_s();
	void set_d(int d);
	int get_d();
	void set_w(int w);
	int get_w();
	string toString();
	static bool ASC(Edge e1, Edge e2);
};
#endif EDGE_H