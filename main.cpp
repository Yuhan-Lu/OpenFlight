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
    vector<int> res = airlineFlow.getAirlineBetweenAirports(4355, 3876);
    for (int i : res) cout << i << endl;
    return 0;
}