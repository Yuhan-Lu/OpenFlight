#pragma once
#include "airlines.h"
#include "airports.h"
#include "planes.h"
#include "routes.h"
#include "cs225/graph.h"
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class AirlineFlow {
    public:
        /**
         * Initialization of the analysis
         */
        AirlineFlow(bool test);

        /**
         * Destructor
         */
        ~AirlineFlow();

        /**
         * Find all the routes ID that flies from source to desination
         * @param sourceAirportID the ID of the source airport
         * @param destAirportID the ID of the destination airport
         */
        vector<int> getAirlineBetweenAirports(int sourceAirportID, int destAirportID);

    private:
        /** All the airlines */
        Airlines* _airlines;
        
        /** All the airports */
        Airports* _airports;
        
        /** All the planes */
        Planes* _planes;
        
        /** All the routes */
        Routes* _routes;

        /**
         * A weighted directed graph using airport ID as vertices and using the number of
         * airlines fly the same route as the edge
         */
        Graph _airlineMap;
        
        /**
         * An unordered map using concatenated string "airportIDSource" + "_" + "airportIDDestination"
         * as key and the vector that holds all the airline IDs as value
         */
        unordered_map<string, vector<int>> _edgeList;

};
