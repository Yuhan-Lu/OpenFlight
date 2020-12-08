#include <iostream>
#include <list>
#include "BFS.h"
#include <algorithm>
#include <limits>

using std::stoi;

namespace bfs {
    vector<int> BFS(Graph G, int start) {
        unordered_map<int, bool> visited;
        vector<int> queue;
        Vertex m;
        vector<int> visitedList;

        //set all vertices not not to be visited except the start
        for (auto & vertex : G.getVertices()) {
            int v = stoi(vertex);
            //cout<<v<<endl;
            if (v == start) {
                //cout<<v<<endl;
                visited[v] = true;
                visitedList.push_back(v);
                break;
            } else {
                visited[v] = false;
            }
            
        }

        //add start node to the quene;
        int s = start;
        queue.push_back(s);

        while(!queue.empty()) {
            s = queue.front();
            queue.erase(queue.begin());
            m = to_string(s);
            for (auto & neighbour : G.getAdjacent(m)) {
                int v = stoi(neighbour);
                if (!visited[v]) {
                    visited[v] = true;
                    visitedList.push_back(v);
                    queue.push_back(v);
                }
            }
            
        }
        return visitedList;

    }
}