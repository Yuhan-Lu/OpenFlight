#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include "airlines.h"
#include "airports.h"
#include "routes.h"
#include "planes.h"
#include "airlineFlow.h"
#include "cs225/graph.h"
#include "Dijkstra.h"
#include "pagerank.cpp"

using std::cout;
using std::endl;

int main() {

    AirlineFlow airlineFlow(true);
    vector<Vertex> res1 = airlineFlow.dfs();
    std::sort(res1.begin(), res1.end(), [](auto &left, auto &right) {
        return std::stoi(left) < std::stoi(right);
    });
    // for (Vertex i : res1) cout << i << endl;
    cout << "SIZE:\t" << res1.size() << endl;
    
    vector<int> res2 = shortest_path(airlineFlow.getRouteGraph(), 2965, 2922);
    for (int i : res2) {
        cout << i << endl;
    }

    AirlineFlow* testalf = new AirlineFlow(true);
    Graph* g = testalf->getRouteGraph();
    Pagerank pagerank1(g, true);
    return 0;
    
}