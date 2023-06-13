#include "MST.h"

MST::MST() {}

MST::MST(int s, int w, int t, Edge* r) 
{
	this->size = s;
	this->weight = w;
	this->time = t;
	this->result = r;
}

int MST::get_w() 
{
	return weight;
}

int MST::get_t() 
{
	return time;
}
Edge* MST::get_r() 
{
	return result;
}

string MST::toString(bool printTree) 
{
	string val = "Waga MST: " + to_string(weight) + "\n";
	if (printTree) 
	{
		for (int i = 0; i < size; i++)
		{
			if (i == 0) val = val + result[i].toString();
			else val = val + ", " + result[i].toString();
		}
		val = val + "\n" + "Czas wykonywania algorytmu: " + to_string(time) + "ms\n";
	}
	else val = val + "Czas liczenia: " + to_string(time) + "ms\n";
	return val;
}