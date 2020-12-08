#include "Dijkstra.h"
#include <algorithm>
#include <limits>

using namespace std;
using std::stoi;


vector<int> shortest_path(Graph G, int source, int dest) {
    unordered_map<int, int> dist; // a map to correspond each vertex to its dist from source
    unordered_map<int, int> previous; // maps current vertex -> its previous vetex
    vector<int> pq; // the priority queue
    vector<int> path; // the vector used to store the vertices along the shortest path

    int INF = numeric_limits<int>::max();
    auto comparator = [&] (int first, int sec) { return dist[first] > dist[sec]; };

    // loop through all the vertices to initialize pq and dist
    for (auto & vertex : G.getVertices()) {
        int v = stoi(vertex);
        if (v == source) {
            dist[v] = 0;
        } else {
            dist[v] = INF;
        }
        pq.push_back(v);
        push_heap(pq.begin(), pq.end(), comparator);
    }

    //while the priority queue is not empty
    while (!pq.empty()) {
        pop_heap(pq.begin(), pq.end(), comparator);
        int min = pq.back();
        pq.pop_back();
        Vertex m = to_string(min);

        if (dist[min] == INF) {
            break;
        }

        //loop through all the neighbours of the current min
        for (auto & neighbour : G.getAdjacent(m)) {
            int cost = G.getEdgeWeight(m, neighbour);
            if (dist[min] + cost < dist[stoi(neighbour)]) {
                //update neighbour's distances
                dist[stoi(neighbour)] = min + cost;
                previous[stoi(neighbour)] = min;
                make_heap(pq.begin(), pq.end(), comparator);
            }
        }

        // once we reach the dest, push all the values to path
        if (min == dest) {
            while(previous.find(min) != previous.end()) {
                path.push_back(min);
                min = previous[min];
            }
            break;
        }

    }
    //reverse path to get the correct direction
    reverse(path.begin(), path.end());
    return path;

}