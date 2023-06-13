#ifndef FINDUNION_H
#define FINDUNION_H

#include <iostream>
#include <vector>

using namespace std;

class FindUnion
{
	vector<int> parent;
	vector<int> rank;
public:
	FindUnion(int n);
	int find(int x);
	void _union(int x, int y);
};
#endif FINDUNION_H
