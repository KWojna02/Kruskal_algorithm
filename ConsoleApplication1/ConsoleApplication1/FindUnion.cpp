#include "FindUnion.h"



FindUnion::FindUnion(int n)
{
	parent.resize(n);
	rank.resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
}

int FindUnion::find(int x) 
{
	if (parent[x] != x) parent[x] = find(parent[x]);
	return parent[x];
}

void FindUnion::_union(int x, int y)
{
	int rootX = find(x);
	int rootY = find(y);
	if (rootX != rootY)
	{
		if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
		else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
		else
		{
			parent[rootY] = rootX;
			rank[rootX]++;
		}
	}
}