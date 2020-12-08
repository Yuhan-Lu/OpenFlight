#pragma once
#include "airlines.h"
#include "airports.h"
#include "planes.h"
#include "routes.h"
#include "cs225/graph.h"
#include "cs225/dsets.cpp"
#include <unordered_map>
#include <vector>
#include <random>
#include <sys/time.h>

using std::unordered_map;
using std::vector;
using std::default_random_engine;

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

        /**
         * Find all the routes ID that flies from source to desination
         * @param sourceIATA the IATA of the source airport
         * @param destIATA the IATA of the destination airport
         */
        vector<int> getAirlineBetweenAirports(string sourceIATA, string destIATA);

        /**
         * Return the graph that containing all the routes, the graph cannot be modified
         * @returns the graph constructed
         */
        Graph* getRouteGraph() const;

        vector<Vertex> bfs(int startAirportID = -1);

        vector<Vertex> dfs(int startAirportID = -1);


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
        Graph* _routeGraph;
        
        /**
         * An unordered map using concatenated string "airportIDSource" + "_" + "airportIDDestination"
         * as key and the vector that holds all the airline IDs as value
         */
        unordered_map<string, vector<int>> _edgeList;

        vector<Vertex> _bfsResult;

        string _bfsStartingAirportID = "-1";

        vector<Vertex> _dfsResult;
        
        string _dfsStartingAirportID = "-1";

        DisjointSets<string> _d;

        default_random_engine _rng;

};
