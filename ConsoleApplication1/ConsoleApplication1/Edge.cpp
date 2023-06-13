#include "Edge.h"

Edge::Edge() {}

Edge::Edge(int s, int d, int w)
{
	this->source = s;
	this->destination = d;
	this->weight = w;
}

void Edge::set_s(int s)
{
	source = s;
}

int Edge::get_s()
{
	return source;
}

void Edge::set_d(int d)
{
	destination = d;
}

int Edge::get_d()
{
	return destination;
}

void Edge::set_w(int w)
{
	weight = w;
}

int Edge::get_w()
{
	return weight;
}

string Edge::toString() 
{
	return to_string(source) + " " + to_string(destination) + " " + to_string(weight);
}

bool Edge::increasing(Edge e1, Edge e2)
{
	return e1.get_w() > e2.get_w();
}