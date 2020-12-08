#include <iostream>
#include <map>
#include "airlines.h"
#include "airports.h"
#include "routes.h"
#include "planes.h"
#include "airlineFlow.h"
#include "cs225/graph.h"
#include "Dijkstra.h"
#include "BFS.h"
#include <list>
#include "cs225/graph.h"
#include "utils.h"


using std::cout;
using std::endl;


std::list<int> *intList; 

void addEdge(int v, int w)
{
    intList[v].push_back(w); // Add w to v’s list.
}

int main() {
    AirlineFlow airlineFlow(false);
    vector<int> res = bfs::BFS(airlineFlow.getGraph(), 2965);
    //vector<int> res = shortest_path(airlineFlow.getGraph(),2948,2965);
    // for (int i : res) {
    //     cout << i << endl;
    // }
    cout<< "the size is " << res.size() << endl;
    return 0;
}
