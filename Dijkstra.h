#pragma once
#include "airlines.h"
#include "airports.h"
#include "planes.h"
#include "routes.h"
#include "airlineFlow.h"
#include "cs225/graph.h"
#include <unordered_map>
#include <vector>

/**
 * use Dijkstra's Algorithm to find the shortest path between airports
 * @param G the loaded graph
 * @param source the ID of the source airport
 * @param dest the ID of the destination airport
 * @return a vector of int showing the airportids along the shortest path
*/
vector<string> shortest_path(Graph* G, int source, int dest, bool test);