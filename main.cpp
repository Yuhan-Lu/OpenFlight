
#include <iostream>
#include <map>
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

    AirlineFlow airlineFlow(true);
    vector<int> res = shortest_path(airlineFlow.getGraph(), 2965, 2922);
    for (int i : res) {
        cout << i << endl;
    }
    return 0;
}

