#include <iostream>
#include <list>
#include "BFS.h"
#include <algorithm>
#include <limits>

vector<bool> Traversal::BFS(Graph G, int start) {
    vector<bool> visited;
    vector<int> queue;
    Vertex m;

    //set all vertices not not to be visited except the start
    for (auto & vertex : G.getVertices()) {
        int v = stoi(vertex);
        if (v == start) {
            visited[v] = true;
        } else {
            visited[v] = false;
        }
        
    }

    //add start node to the quene;
    int s = start;
    queue.push_back(s);

    while(!queue.empty()) {
        s = queue.front();
        queue.erase(queue.begin);
        m = to_string(s);
        for (auto & neighbour : G.getAdjacent(m)) {
            int v = stoi(neighbour);
            if (!visited[v]) {
                visited[v] = true;
                queue.push_back(v);
            }
        }
        
    }
    return visited;

}