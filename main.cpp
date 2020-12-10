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

    AirlineFlow airlineFlow(true); // load graphs, true for test routes, false for actual routes

    //test getEdgeWeight
    cout << airlineFlow.getRouteGraph()->getEdgeWeight(to_string(2948), to_string(2990)) << endl;

    //test getAirline
    vector<int> airlines = airlineFlow.getAirlineBetweenAirports("AER", "KZN");
    for (int i : airlines) {
        cout << i << endl;
    }

    //test bfs
    vector<Vertex> res1 = airlineFlow.bfs();
    std::sort(res1.begin(), res1.end(), [](auto &left, auto &right) {
        return std::stoi(left) < std::stoi(right);
    });
    for (Vertex i : res1) cout << i << endl;
    cout << "SIZE:\t" << res1.size() << endl;

    //test shortest_path
    vector<string> res2 = shortest_path(airlineFlow.getRouteGraph(), 2965, 2922, false);
    for (string i : res2) {
        cout << i << endl;
    }
  
    //test page rank
    Graph* g = airlineFlow.getRouteGraph();
    Pagerank pagerank1(g, false);
    Matrix* mat = pagerank1.returnMatrix();
    for (int i = 0; i < mat->numRows(); i++) {
        for (int j = 0; j < mat->numCols(); j++) {
            cout << mat->getEntry(i, j) << endl;
        }
    }

    return 0;
    
}