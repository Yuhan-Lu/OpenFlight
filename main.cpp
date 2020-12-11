#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include "airlines.h"
#include "airports.h"
#include "routes.h"
#include "planes.h"
#include "airlineFlow.h"
#include "cs225/graph.h"
#include "Dijkstra.h"
#include "pagerank.cpp"

using std::cout;
using std::endl;

int main() {

    AirlineFlow airlineFlow(false); // load graphs, true for test routes, false for actual routes

    //test getEdgeWeight
    cout << airlineFlow.getRouteGraph()->getEdgeWeight(to_string(2965), to_string(2990)) << " km."  << endl;

    //test getAirline
    vector<int> airlines = airlineFlow.getAirlineBetweenAirports("AER", "KZN");
    cout << "airlines between the two airports:" << endl;
    for (int i : airlines) {
        cout << "airline No." << i << endl;
    }

    //test bfs
    vector<Vertex> res1 = airlineFlow.bfs();
    std::sort(res1.begin(), res1.end(), [](auto &left, auto &right) {
        return std::stoi(left) < std::stoi(right);
    });
    cout << "bfs traversal route:" << endl;
    for (Vertex i : res1) cout << i << endl;
    cout << "SIZE:\t" << res1.size() << endl;

    //test shortest_path
    vector<string> res2 = shortest_path(airlineFlow.getRouteGraph(), 2965, 2922, false);
    for (string i : res2) {
        cout << i << endl;
    }
  
    //test page rank
    Graph* g = airlineFlow.getRouteGraph();
    Pagerank pagerank1(g, false);
    Matrix* mat = pagerank1.returnMatrix();
    mat->convertToDampingMatrix(0.85);
    // mat->printMatrix();

    Matrix * temp = Matrix::initialVector(mat->numRows());
    // temp->printMatrix();
    Matrix* lastMatrix = new Matrix(temp->shape());
    int runTime = 0;
    
    while(utils::matrixSub(temp, lastMatrix)->norm() > powl(10, -8)) {
        lastMatrix = temp;
        temp = utils::matrixMul(mat, temp);
        temp = temp->normalize();
        runTime++;
    }

    vector<long double> res = temp->toVector();
    // for (auto it = res.begin(); it != res.end(); ++it) {
    //     cout << *it << endl;
    // }
    vector<pair<int, long double>> groupedVec;
    for (int i = 0; i < (int) res.size(); i++) {
        groupedVec.push_back(std::pair<int, long double>(stoi(g->getVertices().at(i)), res[i]));
    }
    std::sort(groupedVec.begin(), groupedVec.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });
    Airports* a = airlineFlow.getAirportDataset();
    int ranking = 1;
    for (auto it = groupedVec.begin(); it != groupedVec.end(); ++it) {
        std::pair<int, string> dataPair(it->first, a->getAirportByID(it->first)->name);
        // cout << it->first << " \t" << a->getAirportByID(it->first)->name << endl;
    }

    

    return 0;
    
}