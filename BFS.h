#pragma once
#include "airlines.h"
#include "airports.h"
#include "planes.h"
#include "routes.h"
#include "airlineFlow.h"
#include "cs225/graph.h"
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>

using std::unordered_map;
using std::vector;

class Traversal {
    public:
    /**
    * use BFS to traverse all vertex in the graph
    * @param start the start point on the graph
    */
    vector<bool> BFS(Graph G, int start);

    private:
    Graph _airlineMap;



};



