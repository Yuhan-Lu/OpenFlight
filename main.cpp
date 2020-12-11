#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include "airlines.h"
#include "airports.h"
#include "routes.h"
#include "planes.h"
#include "random"
#include "airlineFlow.h"
#include "cs225/graph.h"
#include "Dijkstra.h"
#include "pagerank.cpp"

using std::cout;
using std::endl;
using std::string;

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
    for (auto airport : g->getVertices()) {
        cout << "airportsID " << airport << endl;
    }
    Pagerank pagerank1(g, false);
    Matrix* mat = pagerank1.returnMatrix();
<<<<<<< HEAD
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

    
=======
    mat->convertToDampingMatrix(0.8);
    int cols = mat->numCols();
    int rows = mat->numRows();
    mat->printMatrix();

    long double maxPop = 0;
    int maxRow = 0;
    Matrix * temp = Matrix::initialVector(rows);
    //temp->printMatrix();
    Matrix* lastMatrix = new Matrix(temp->shape());
    int runTime = 0;
    
    // while(utils::matrixSub(temp, lastMatrix)->norm() > powl(10, -8)) {
    //     lastMatrix = temp;
    //     temp = utils::matrixMul(mat, temp);
        
    //     temp = temp->normalize();
    //     //temp->printMatrix();
    //     cout << utils::matrixSub(temp, lastMatrix)->norm() ;
    //     runTime++;
    // }

    for(int i = 0; i < 100; i++) {
        temp = utils::matrixMul(mat, temp);

    }

    
    for(int i = 0; i < rows; i++) {
        if (maxPop <= temp->getEntry(i, 0)) {
            maxPop = temp->getEntry(i, 0);
            maxRow = i;
        }
    }
    int stupid = maxPop;
    maxPop = 0;
    int maxRow1 = 0;
    for(int i = 0; i < rows; i++) {
        if (maxPop <= temp->getEntry(i, 0) && maxPop != stupid) {
            maxPop = temp->getEntry(i, 0);
            maxRow1 = i;
        }
    }
    //cout << "----------------"<< endl;
    temp->printMatrix();
    Airports* airports = new Airports(true);
    //vector<int> maxairportID;
   
    string airportName = airports->getAirportByID(stoi((g->getVertices()).at(maxRow)))->name;
    cout << "the most popular airport is: " << airportName << endl;
    cout << "the most popular airport is: " << airports->getAirportByID(stoi((g->getVertices()).at(maxRow1)))->name << endl;
    //cout << airportName << " has " << g->getVertices().at(maxRow).size() << "" << endl;
    
    // cout << temp->getEntry(maxRow, 0) << endl;
    // cout << temp->getEntry(731, 0) << endl;
    // cout << g->getVertices().size() << endl;
    // long double sum = 0;
    // for(int i = 0; i < rows; i++) {
    //     sum+=temp->getEntry(i, 0);
    // }
    // cout << "sum: " << sum << endl;
>>>>>>> 1f302051f70ea2945ef444ba62a5fa1ad6defa6a

    return 0;
}