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

namespace bfs {
    /**
    * use BFS to traverse all vertex in the graph
    * @param start the ID of the source airport
    */
    vector<int> BFS(Graph G, int start);

};



