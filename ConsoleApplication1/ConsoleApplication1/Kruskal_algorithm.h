#ifndef KRUSKAL_ALGORITHM_H
#define KRUSKAL_ALGORITHM_H

#include "Lista.h"
#include "MST.h"
#include "PriorityQueue.h"
#include "FindUnion.h"
#include <chrono>

class Kruskal_algorithm
{
public:
	MST getTree_PQ(Edge* tab, int size);
	MST getTree_List(Edge* tab, int size);
};

#endif KRUSKAL_ALGORITHM_H
