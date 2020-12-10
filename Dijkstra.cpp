#include "Dijkstra.h"

#include <algorithm>
#include <limits>

using namespace std;
using std::stoi;

vector<string> shortest_path(Graph* G, int source, int dest, bool test) {
    unordered_map<int, int> dist; // a map to correspond each vertex to its dist from source
    unordered_map<int, int> previous; // maps current vertex -> its previous vetex
    unordered_map<int, bool> visited;
    vector<int> pq; // the priority queue
    vector<int> path; // the vector used to store the airportIDs along the shortest path
    vector<string> path_s; //the vector used to store the airport names along the shortest path
    int totaldist = 0;
    int INF = numeric_limits<int>::max();
    auto comparator = [&] (int first, int sec) { return dist[first] > dist[sec]; };

    //make_heap(pq.begin(), pq.end(), comparator);
    // loop through all the vertices to initialize pq and dist
    for (auto & vertex : G->getVertices()) {
        int v = stoi(vertex);
        if (v == source) {
            dist[v] = 0;
        } else {
            dist[v] = INF;
            visited[v] = false;
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
        visited[min] = true;
        // once we reach the dest, push all the values to path
        if (min == dest) {
            while(previous.find(min) != previous.end()) {
                totaldist += dist[min];
                path.push_back(min);
                min = previous[min];
            }

            break;
        }

        if (dist[min] == INF) {
            break;
        }

        //loop through all the neighbours of the current min
        for (auto & neighbour : G->getAdjacent(m)) {
            int cost = G->getEdgeWeight(m, neighbour);
            if (!visited[stoi(neighbour)] && G->edgeExists(m, neighbour)
                 && dist[min] + cost < dist[stoi(neighbour)]) {
                //update neighbour's distances
                previous[stoi(neighbour)] = min;
                dist[stoi(neighbour)] = dist[min] + cost;
                make_heap(pq.begin(), pq.end(), comparator);
            }
        }



    }

    
    //reverse path to get the correct direction
    reverse(path.begin(), path.end());

    Airports* airports = new Airports(test);
    for (int i : path) {
        Airports::AirportNode* node = airports->getAirportByID(i);
        path_s.push_back(node->name);
    }

    delete airports;
    cout << "total dist is " << totaldist << endl;
    return path_s;

}