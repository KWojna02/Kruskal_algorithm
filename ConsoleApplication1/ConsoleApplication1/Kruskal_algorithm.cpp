#include "Kruskal_algorithm.h"

MST Kruskal_algorithm::getTree_PQ(Edge* tab, int size)
{
	PriorityQueue<Edge> queue = PriorityQueue<Edge>(size, Edge::increasing);
	Edge* result = new Edge[size];
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++) 
	{
		queue.push(tab[i]);
	}
	int count = 0, index = 0, weight = 0;
	FindUnion fu(size);
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
			fu._union(rootS, rootD);
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
	list.quickSort(left, right, Edge::increasing);
	int count = 0, index = 0, weight = 0;
	FindUnion fu(size);
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
			fu._union(rootS, rootD);
		}
		index++;
	}
	auto end = chrono::high_resolution_clock::now();
	auto time = chrono::duration_cast<chrono::milliseconds>(end - start);
	return MST(weight, count, time.count(), result);
}