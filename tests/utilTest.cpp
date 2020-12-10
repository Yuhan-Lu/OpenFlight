#include "../cs225/catch/catch.hpp"

#include "../airlines.h"
#include "../airports.h"
#include "../planes.h"
#include "../routes.h"
#include "../utils.h"
#include "../pagerank.h"
#include "../airlineFlow.h"
#include "../Dijkstra.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using namespace utils;

bool longDoubleEqual(long double d1, long double d2) {
  return abs(d1 - d2) < TOL;
}

TEST_CASE("check distance and route.cpp distance", "[valgrind][weight=1]") {
  Airports airports(true);
  double lati1 = airports.getAirportByID(2965)->latit;
  double longti1 = airports.getAirportByID(2965)->longit;
  double lati2 = airports.getAirportByID(2990)->latit;
  double longti2 = airports.getAirportByID(2990)->longit;
  double dist = getDistance(lati1,longti1,lati2,longti2);
  //std::cout << dist << std::endl;
  REQUIRE(dist == getDistance(43.449902,39.9566,55.606201171875,49.278701782227));
  
  
}

TEST_CASE("check graph loading", "[valgrind][weight=1]") {
  AirlineFlow airlineflow(true);
  vector<int> airlines = airlineflow.getAirlineBetweenAirports("AER", "KZN");
  REQUIRE(airlines.size() == 1);
  REQUIRE(airlines.at(0) == 410);

  //check vertices
  REQUIRE(airlineflow.getRouteGraph()->vertexExists(to_string(2965)));
  REQUIRE(airlineflow.getRouteGraph()->vertexExists(to_string(2948)));
  REQUIRE(airlineflow.getRouteGraph()->vertexExists(to_string(2990)));
  REQUIRE(airlineflow.getRouteGraph()->vertexExists(to_string(3830)) == false);


  //check edge weight
  int weight_loaded = airlineflow.getRouteGraph()->getEdgeWeight(to_string(2948), to_string(2990));
  Airports airports(true);
  double sourceLatitude = airports.getAirportByID(2948)->latit;
  double sourceLongitude = airports.getAirportByID(2948)->longit;
  double destLatitude = airports.getAirportByID(2990)->latit;
  double destLongitude = airports.getAirportByID(2990)->longit;
  int weight_actual = getDistance(sourceLatitude, sourceLongitude, destLatitude, destLongitude);
  REQUIRE(weight_loaded == weight_actual);

}

TEST_CASE("check dfs and bfs on test routes", "[valgrind][weight=1]") {
    AirlineFlow airlineFlow(true);
    //dfs
    vector<Vertex> res1 = airlineFlow.dfs();
    REQUIRE(res1.size() == 8);
    std::sort(res1.begin(), res1.end(), [](auto &left, auto &right) {
        return std::stoi(left) < std::stoi(right);
    });
    REQUIRE(res1.at(0) == to_string(2922));

    //bfs
    vector<Vertex> res2 = airlineFlow.bfs();
    REQUIRE(res2.size() == 8);
    std::sort(res2.begin(), res2.end(), [](auto &left, auto &right) {
        return std::stoi(left) < std::stoi(right);
    });
    REQUIRE(res2.at(0) == to_string(2922));

}

TEST_CASE("check matrix subtraction", "[valgrind][weight=1]") {
  //{ {2, -1}, {-1, 1}};
  long double** value1;
  value1 = new long double*[2];
  for (int i = 0; i < 2; i++) {
    value1[i] = new long double[2];
  }
  value1[0][0] = 2.0;
  value1[0][1] = -1.0;
  value1[1][0] = -1.0;
  value1[1][1] = 1.0;

  //{ {1, 3}, {1, 1}};
  long double** value2;
  value2 = new long double*[2];
  for (int i = 0; i < 2; i++) {
    value2[i] = new long double[2];
  }
  value2[0][0] = 1.0;
  value2[0][1] = 3.0;
  value2[1][0] = 1.0;
  value2[1][1] = 1.0;
  
  //{ {1, -4}, {-2, 0}};
  long double** ans;
  ans = new long double*[2];
  for (int i = 0; i < 2; i++) {
    ans[i] = new long double[2];
  }
  ans[0][0] = 1;
  ans[0][1] = -4;
  ans[1][0] = -2;
  ans[1][1] = 0;
  
  Matrix* mat1 = new Matrix(2, 2, value1);
  Matrix* mat2 = new Matrix(2, 2, value2);
  Matrix* matAns = new Matrix(2, 2, ans);
  
  REQUIRE(*matrixSub(mat1, mat2) == *matAns);

  delete mat1;
  delete mat2;
  delete matAns;
}

TEST_CASE("check matrix multiplication", "[valgrind][weight=1]") {
  //{ {2, -1}, {-1, 1}};
  long double** value1;
  value1 = new long double*[2];
  for (int i = 0; i < 2; i++) {
    value1[i] = new long double[2];
  }
  value1[0][0] = 2.0;
  value1[0][1] = -1.0;
  value1[1][0] = -1.0;
  value1[1][1] = 1.0;

  //{ {1, 3}, {1, 1}};
  long double** value2;
  value2 = new long double*[2];
  for (int i = 0; i < 2; i++) {
    value2[i] = new long double[2];
  }
  value2[0][0] = 1.0;
  value2[0][1] = 3.0;
  value2[1][0] = 1.0;
  value2[1][1] = 1.0;
  
  //{ {1, 5}, {0, -2}};
  long double** ans;
  ans = new long double*[2];
  for (int i = 0; i < 2; i++) {
    ans[i] = new long double[2];
  }
  ans[0][0] = 1;
  ans[0][1] = 5;
  ans[1][0] = 0;
  ans[1][1] = -2;
  
  Matrix* mat1 = new Matrix(2, 2, value1);
  Matrix* mat2 = new Matrix(2, 2, value2);
  Matrix* matAns = new Matrix(2, 2, ans);
  
  REQUIRE(*matrixMul(mat1, mat2) == *matAns);

  delete mat1;
  delete mat2;
  delete matAns;
}


TEST_CASE("check matrix multiplication Larger", "[valgrind][weight=1]") {
// A = np.array([[1, 2, -3, 4], 
//              [1, 2, -3, -4],
//              [1, 2, -3, 4],
//              [1, 2, -3, 4]])
  long double** value1;
  value1 = new long double*[4];
  for (int i = 0; i < 4; i++) {
    value1[i] = new long double[4];
  }
  value1[0][0] = 1;
  value1[0][1] = 2;
  value1[0][2] = -3;
  value1[0][3] = 4;
  value1[1][0] = 1;
  value1[1][1] = 2;
  value1[1][2] = -3;
  value1[1][3] = -4;
  value1[2][0] = 1;
  value1[2][1] = 2;
  value1[2][2] = -3;
  value1[2][3] = 4;
  value1[3][0] = 1;
  value1[3][1] = 2;
  value1[3][2] = -3;
  value1[3][3] = 4;

// B = np.array([[1, 2, -3, 4], 
//              [1, 2, -3, -4],
//              [1, 2, -3, 4],
//              [1, 2, -3, 4]])
  long double** value2;
  value2 = new long double*[4];
  for (int i = 0; i < 4; i++) {
    value2[i] = new long double[4];
  }
  value2[0][0] = 1;
  value2[0][1] = 2;
  value2[0][2] = -3;
  value2[0][3] = 4;
  value2[1][0] = 1;
  value2[1][1] = 2;
  value2[1][2] = -3;
  value2[1][3] = -4;
  value2[2][0] = 1;
  value2[2][1] = 2;
  value2[2][2] = -3;
  value2[2][3] = 4;
  value2[3][0] = 1;
  value2[3][1] = 2;
  value2[3][2] = -3;
  value2[3][3] = 4;
  
// Ans = array([[  4,   8, -12,   0],
//             [ -4,  -8,  12, -32],
//             [  4,   8, -12,   0],
//             [  4,   8, -12,   0]])
  long double** ans;
  ans = new long double*[4];
  for (int i = 0; i < 4; i++) {
    ans[i] = new long double[4];
  }
  ans[0][0] = 4;
  ans[0][1] = 8;
  ans[0][2] = -12;
  ans[0][3] = 0;
  ans[1][0] = -4;
  ans[1][1] = -8;
  ans[1][2] = 12;
  ans[1][3] = -32;
  ans[2][0] = 4;
  ans[2][1] = 8;
  ans[2][2] = -12;
  ans[2][3] = 0;
  ans[3][0] = 4;
  ans[3][1] = 8;
  ans[3][2] = -12;
  ans[3][3] = 0;
  
  Matrix* mat1 = new Matrix(4, 4, value1);
  Matrix* mat2 = new Matrix(4, 4, value2);
  Matrix* matAns = new Matrix(4, 4, ans);

  REQUIRE(*matrixMul(mat1, mat2) == *matAns);
  
  delete mat1;
  delete mat2;
  delete matAns;
}

TEST_CASE("norm", "norm") {
// A = np.array([0.83693831, 0.31719906, 0.51235507, 0.07216965, 0.32061431,
//        0.85697327, 0.17513264, 0.49080132, 0.30565907, 0.22081496])
  long double** vec;
  vec = new long double*[10];
  for (int i = 0; i < 10; i++) {
    vec[i] = new long double[1];
  }
  vec[0][0] = 0.836938;
  vec[1][0] = 0.317199;
  vec[2][0] = 0.512355;
  vec[3][0] = 0.072170;
  vec[4][0] = 0.320614;
  vec[5][0] = 0.856973;
  vec[6][0] = 0.175133;
  vec[7][0] = 0.490801;
  vec[8][0] = 0.305659;
  vec[9][0] = 0.220815;
  
  Matrix* mat = new Matrix(10, 1, vec);
  REQUIRE(longDoubleEqual(mat->norm(), 1.5230686001829294));
  
  delete mat;
}

TEST_CASE("normalize", "norm") {
// A = np.array([0.83693831, 0.31719906, 0.51235507, 0.07216965, 0.32061431,
//        0.85697327, 0.17513264, 0.49080132, 0.30565907, 0.22081496])
  long double** vec;
  vec = new long double*[10];
  for (int i = 0; i < 10; i++) {
    vec[i] = new long double[1];
  }
  vec[0][0] = 0.836938;
  vec[1][0] = 0.317199;
  vec[2][0] = 0.512355;
  vec[3][0] = 0.072170;
  vec[4][0] = 0.320614;
  vec[5][0] = 0.856973;
  vec[6][0] = 0.175133;
  vec[7][0] = 0.490801;
  vec[8][0] = 0.305659;
  vec[9][0] = 0.220815;
  
  Matrix* mat1 = new Matrix(10, 1, vec);
// A_norm = array([0.54950796, 0.20826314, 0.33639658, 0.04738437, 0.2105055 ,
//        0.56266229, 0.1149867 , 0.32224505, 0.20068634, 0.14498031])
  long double** res;
  res = new long double*[10];
  for (int i = 0; i < 10; i++) {
    res[i] = new long double[1];
  }
  res[0][0] = 0.549508;
  res[1][0] = 0.208263;
  res[2][0] = 0.336397;
  res[3][0] = 0.047384;
  res[4][0] = 0.210505;
  res[5][0] = 0.562662;
  res[6][0] = 0.114987;
  res[7][0] = 0.322245;
  res[8][0] = 0.200686;
  res[9][0] = 0.144980;
  Matrix* mat2 = new Matrix(10, 1, res);

  Matrix* normalized = mat1->normalize();
  REQUIRE(*normalized == *mat2);

  delete mat1;
  delete mat2;
  delete normalized;
}

TEST_CASE("initializeVector", "norm") {
  Matrix* mat = Matrix::initialVector(10);
  REQUIRE(longDoubleEqual(mat->norm(), 1));
  delete mat;
}


//see testRoutesIMG.jpg
TEST_CASE("check shortest path on test routes", "[valgrind][weight=1]") {
  AirlineFlow airlineFlow(true);
  vector<string> res2 = shortest_path(airlineFlow.getRouteGraph(), 2965, 2922, true);
  REQUIRE(res2.size() == 4);
  REQUIRE(res2[0] == "Kazan International Airport");
  REQUIRE(res2[1] == "Koltsovo Airport");
  REQUIRE(res2[2] == "Begishevo Airport");
  REQUIRE(res2[3] == "Heydar Aliyev International Airport");
}

TEST_CASE("check shortest path on actual routes - CMI to ORD", "[valgrind][weight=1]") {
  AirlineFlow airlineFlow(false);
  vector<string> res2 = shortest_path(airlineFlow.getRouteGraph(), 4049, 3830, false);
  REQUIRE(res2.size() == 1);
  REQUIRE(res2[0] == "Chicago O'Hare International Airport");
}

TEST_CASE("check shortest path on actual routes - CAN to HKG", "[valgrind][weight=1]") {
  AirlineFlow airlineFlow(false);
  vector<string> res2 = shortest_path(airlineFlow.getRouteGraph(), 3370, 3077, false);
  REQUIRE(res2.size() == 1);
  REQUIRE(res2[0] == "Hong Kong International Airport");
}

TEST_CASE("check shortest path on actual routes - CAN to ORD", "[valgrind][weight=1]") {
  AirlineFlow airlineFlow(false);
  vector<string> res2 = shortest_path(airlineFlow.getRouteGraph(), 3370, 3830, false);
  REQUIRE(res2.size() == 2);
  REQUIRE(res2[0] == "Beijing Capital International Airport");
  REQUIRE(res2[1] == "Chicago O'Hare International Airport");
}
