#include <iostream>
#include "PriorityQueue.h"
#include "Graph.h"
#include "MST.h"
#include "Kruskal_algorithm.h"

int main()
{
    Graph graph;
    Edge* edges = graph.getGraph("C:/Users/Abc/Desktop/g10.txt");

    Kruskal_algorithm kruskal;
    //MST mst_l = kruskal.getTree_List(edges, graph.getSize());
    
    
    //cout << mst_l.toString(false) << endl;
    MST mst_pq = kruskal.getTree_PQ(edges, 10);
    cout << mst_pq.toString(true) << endl;
    return 0;
}
