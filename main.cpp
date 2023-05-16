#include "DirectedUnweightedGraph.h"
#include <fstream>

int main() {
    cout << "Graph 1:" << endl;
    DirectedUnweightedGraph graph(6);
    graph.addEdge({ 0, 1 });
    graph.addEdge({ 0, 2 });
    graph.addEdge({ 1, 2 });
    graph.addEdge({ 1, 3 });
    graph.addEdge({ 1, 4 });
    graph.addEdge({ 2, 4 });
    graph.addEdge({ 3, 5 });
    graph.addEdge({ 4, 3 });
    graph.addEdge({ 4, 5 });
    cout << "BFS: ";
    graph.BFS();
    cout << endl;
    cout << "DFS: ";
    graph.DFS();
    cout << endl;

    cout << "Graph 2:" << endl;
    DirectedUnweightedGraph graph2(7);
    graph2.addEdge({ 0, 1 });
    graph2.addEdge({ 0, 2 });
    graph2.addEdge({ 1, 2 });
    graph2.addEdge({ 1, 3 });
    graph2.addEdge({ 1, 4 });
    graph2.addEdge({ 2, 4 });
    graph2.addEdge({ 3, 5 });
    graph2.addEdge({ 4, 3 });
    graph2.addEdge({ 4, 5 });
    graph2.addEdge({ 6, 0 });
    cout << "BFS: ";
    graph2.BFS();
    cout << endl;
    cout << "DFS: ";
    graph2.DFS();
    cout << endl;


    ifstream inputFile("Board.txt");

    cout << "Graph 3:" << endl;
    DirectedUnweightedGraph graph3(10);

    if (inputFile.is_open())
    {
        int value;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                inputFile >> value;
                if (value >= 0)
                {
                    graph3.addEdge({ i,j });
                }
            }
        }
        inputFile.close();
            
    }
    else
    {
        cout << "Error: Can't open file" << endl;
    }

    cout << "BFS: ";
    graph3.BFS();
    cout << endl;
    cout << "DFS: ";
    graph3.DFS();
    cout << endl;
    return 0;
}