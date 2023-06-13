#include "Kruskal_algorithm.h"

struct UnionFind
{
	vector<int> parent;
	vector<int> rank;

	UnionFind(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unionSets(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			if (rank[rootX] < rank[rootY]) {
				parent[rootX] = rootY;
			}
			else if (rank[rootX] > rank[rootY]) {
				parent[rootY] = rootX;
			}
			else {
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}
};

MST Kruskal_algorithm::getTree_PQ(Edge* tab, int size)
{
	PriorityQueue<Edge> queue = PriorityQueue<Edge>(size, Edge::ASC);
	Edge* result = new Edge[size];
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++) 
	{
		queue.push(tab[i]);
	}
	int count = 0, index = 0, weight = 0;
	UnionFind fu(size);
	while (index < size)
	{
		Edge edge = queue.top();
		queue.pop();

		int rootS = fu.find(edge.get_s());
		int rootD = fu.find(edge.get_d());
		if (rootS != rootD) 
		{
			result[count] = edge;
			weight += edge.get_w();
			count++;
			fu.unionSets(rootS, rootD);
		}
		index++;
	}
	auto end = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::milliseconds>(end - start);
	return MST(weight, count, time.count(), result);
}

MST Kruskal_algorithm::getTree_List(Edge* tab, int size)
{
	List<Edge> list = List<Edge>();
	Edge* result = new Edge[size];
	for (int i = 0; i < size; i++) 
	{
		list.newItem(tab[i]);
	}
	auto start = chrono::high_resolution_clock::now();
	int left = 0;
	int right = list.getSize() - 1;
	list.quickSort(left, right, Edge::ASC);
	int count = 0, index = 0, weight = 0;
	UnionFind fu(size);
	while (index < size)
	{
		Edge edge = list.getItem(0);
		list.deleteItem(0);

		int rootS = fu.find(edge.get_s());
		int rootD = fu.find(edge.get_d());
		if (rootS != rootD)
		{
			result[count] = edge;
			weight += edge.get_w();
			count++;
			fu.unionSets(rootS, rootD);
		}
		index++;
	}
	auto end = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::milliseconds>(end - start);
	return MST(weight, count, time.count(), result);
}