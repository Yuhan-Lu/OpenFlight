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
#include "cs225/PNG.h"
#include "Dijkstra.h"
#include "pagerank.cpp"
#include "pathDrawer.cpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

const string sep = "\n--------------------------------------------------------------------\n";

int main() {

    AirlineFlow airlineFlow(false); // load graphs, true for test routes, false for actual routes
    Airports airports = airlineFlow.getAirportDataset();
    //AirlineFlow airlineFlow = new AirlineFlow(false);
    //test getEdgeWeight
    cout << airlineFlow.getRouteGraph()->getEdgeWeight(to_string(2965), to_string(2990)) << " km."  << endl;

    cout << sep << endl;

    //test getAirline
    vector<int> airlines = airlineFlow.getAirlineBetweenAirports("AER", "KZN");
    cout << "airlines between the two airports:" << endl;
    for (int i : airlines) {
        cout << "airline No." << i << endl;
    }
    
    cout << sep << endl;

    //test shortest_path
    Dijkstra dijkstra(airlineFlow);
    string dijkstraReport = dijkstra.getShortestPathReport(2965, 2922);
    cout << dijkstraReport;
    
  
    //test page rank
    Graph* g = airlineFlow.getRouteGraph();
    Pagerank* labelLoad = new Pagerank(airlineFlow, false);
    vector<pair<int, string>> pagerankRes = labelLoad->pageRank(0.85);
    string pageRankReport = labelLoad->getPageRankReport();
    cout << pageRankReport;

    PathDrawer pathDrawer(airlineFlow.getAirportDataset());
    pair<int, vector<int>> path = dijkstra.shortestPath(2965, 2922);
    pathDrawer.addPath(path.second);
    PNG* res = pathDrawer.renderPath();
    res->writeToFile("out.png");

    return 0;
}