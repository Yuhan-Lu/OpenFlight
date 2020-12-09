#include <iostream>
#include <map>
#include "airlines.h"
#include "airports.h"
#include "routes.h"
#include "planes.h"
#include "airlineFlow.h"
#include "cs225/graph.h"
#include <algorithm>
#include <fstream>

using std::cout;
using std::endl;

int main() {

    AirlineFlow airlineFlow(false);
    vector<Vertex> res = airlineFlow.dfs();
    std::sort(res.begin(), res.end(), [](auto &left, auto &right) {
        return std::stoi(left) < std::stoi(right);
    });
    // for (Vertex i : res) cout << i << endl;
    cout << "SIZE:\t" << res.size() << endl;
    return 0;
    
}