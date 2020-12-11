#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include "airlines.h"
#include "airports.h"
#include "routes.h"
#include "planes.h"
#include "random"
#include "airlineFlow.h"
#include "cs225/graph.h"
#include "Dijkstra.h"
#include "pagerank.cpp"

using std::cout;
using std::endl;
using std::string;

int main() {

    AirlineFlow airlineFlow(false); // load graphs, true for test routes, false for actual routes
    //AirlineFlow airlineFlow = new AirlineFlow(false);
    //test getEdgeWeight
    cout << airlineFlow.getRouteGraph()->getEdgeWeight(to_string(2965), to_string(2990)) << " km."  << endl;

    //test getAirline
    vector<int> airlines = airlineFlow.getAirlineBetweenAirports("AER", "KZN");
    cout << "airlines between the two airports:" << endl;
    for (int i : airlines) {
        cout << "airline No." << i << endl;
    }

    //test bfs
    vector<Vertex> res1 = airlineFlow.bfs();
    std::sort(res1.begin(), res1.end(), [](auto &left, auto &right) {
        return std::stoi(left) < std::stoi(right);
    });
    cout << "bfs traversal route:" << endl;
    for (Vertex i : res1) cout << i << endl;
    cout << "SIZE:\t" << res1.size() << endl;

    //test shortest_path
    vector<string> res2 = shortest_path(airlineFlow.getRouteGraph(), 2965, 2922, false);
    for (string i : res2) {
        cout << i << endl;
    }
  
    //test page rank
    Graph* g = airlineFlow.getRouteGraph();
    Pagerank * labelLoad = new Pagerank(g, false);
    labelLoad->pagerankOperation(&airlineFlow, 0.85);

    return 0;
}