#pragma once
#include "airlines.h"
#include "airports.h"
#include "planes.h"
#include "routes.h"
#include "airlineFlow.h"
#include "cs225/graph.h"

using std::vector;
using std::string;
using std::pair;

class Dijkstra {
    public:
        /**
         * Constructor of Dijkstra class
         * @param airlineFlow the airlineFlow need
        */
        Dijkstra(AirlineFlow& airlineFlow);

        /**
         * Use Dijkstra's Algorithm to find the shortest path between airports, returns a pair which the
         * first entry is the shortest distance (in kilometers) between airports, and the second entry is 
         * a vector of airport IDs thar this shortest path fly by.
         * @param source the ID of the source airport
         * @param dest the ID of the destination airport
         * @return a pair as described above
        */
        pair<int, vector<int>> shortestPath(int source, int dest);

        string getShortestPathReport(int source, int dest);

    private:
        /** Route graph */
        Graph* _routeGraph;

        /** Airports info */
        Airports* _airports;
};