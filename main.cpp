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

using std::cout;
using std::endl;

int main() {

    AirlineFlow airlineFlow(false);
    // vector<Vertex> res1 = airlineFlow.dfs();
    // std::sort(res1.begin(), res1.end(), [](auto &left, auto &right) {
    //     return std::stoi(left) < std::stoi(right);
    // });
    // // for (Vertex i : res1) cout << i << endl;
    // cout << "SIZE:\t" << res1.size() << endl;
    cout << airlineFlow.getRouteGraph()->getEdgeWeight(to_string(3370), to_string(3830)) << endl;
    vector<string> res2 = shortest_path(airlineFlow.getRouteGraph(), 3370, 3830, false);
    for (string i : res2) {
        cout << i << endl;
    }
    return 0;
    
}