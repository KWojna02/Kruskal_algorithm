#include "Graph.h"

Edge* Graph::getGraph(string filename) 
{
	ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Nie udalo sie otworzyc pliku." << endl;
        return nullptr;
    }
    int s, d, w;

    int maxSize = 10;  // Pocz¹tkowy rozmiar tablicy dynamicznej
    Edge* edges = new Edge[maxSize];
    int numEdges = 0;

    while (file >> s >> d >> w) 
    {
        if (numEdges == maxSize) 
        {
            // Powiêkszanie rozmiaru tablicy dynamicznej, jeœli jest zape³niona
            maxSize *= 2;
            Edge* temp = new Edge[maxSize];
            for (int i = 0; i < numEdges; ++i) 
            {
                temp[i] = edges[i];
            }
            delete[] edges;
            edges = temp;
        }

        edges[numEdges].set_s(s);
        edges[numEdges].set_d(d);
        edges[numEdges].set_w(w);
        numEdges++;
    }

    file.close();
    size = numEdges;
    return edges;
}

int Graph::getSize()
{
    return size;
}