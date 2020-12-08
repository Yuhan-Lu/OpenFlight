#include <iostream>
#include <map>
#include "airlines.h"
#include "airports.h"
#include "routes.h"
#include "planes.h"
#include "airlineFlow.h"
#include "cs225/graph.h"

using std::cout;
using std::endl;

int main() {

    AirlineFlow airlineFlow(false);
    vector<Vertex> res = airlineFlow.dfs();
    // for (Vertex i : res) cout << i << endl;
    cout << "SIZE:\t" << res.size() << endl;
    return 0;
}