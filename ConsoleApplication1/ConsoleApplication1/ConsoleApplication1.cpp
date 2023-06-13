#include <iostream>
#include "PriorityQueue.h"
#include "Graph.h"
#include "MST.h"
#include "Kruskal_algorithm.h"

int main()
{
    Graph graph;
    Edge* edges = graph.getGraph("graph10000.txt");

    Kruskal_algorithm kruskal;

    //MST mst_l = kruskal.getTree_List(edges, graph.getSize());     
    //cout << mst_l.toString(false) << endl;

    MST mst_pq = kruskal.getTree_PQ(edges, graph.getSize());
    cout << mst_pq.toString(false) << endl;
    return 0;
}
