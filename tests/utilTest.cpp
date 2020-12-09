#include "../cs225/catch/catch.hpp"

#include "../airlines.h"
#include "../airports.h"
#include "../planes.h"
#include "../routes.h"
#include "../utils.h"
#include "../pagerank.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using namespace utils;

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

TEST_CASE("check matrix multiplication", "[valgrind][weight=1]") {
  //{ {2, -1}, {-1, 1}};
  double ** value1;
  value1 = new double*[2];
  for (int i = 0; i < 2; i++) {
    value1[i] = new double[2];
  }
  value1[0][0] = 2.0;
  value1[0][1] = -1.0;
  value1[1][0] = -1.0;
  value1[1][1] = 1.0;
  //{ {1, 1}, {1, 1}};
  double ** value2;
  value2 = new double*[2];
  for (int i = 0; i < 2; i++) {
    value2[i] = new double[2];
  }
  value2[0][0] = 1.0;
  value2[0][1] = 3.0;
  value2[1][0] = 1.0;
  value2[1][1] = 1.0;
  
  //{ {1, 5}, {0, -2}};
  double ** ans;
  ans = new double*[2];
  for (int i = 0; i < 2; i++) {
    ans[i] = new double[2];
  }
  ans[0][0] = 1;
  ans[0][1] = 5;
  ans[1][0] = 0;
  ans[1][1] = -2;
  
  Matrix* mat1 = new Matrix(2, 2, value1);
  Matrix* mat2 = new Matrix(2, 2, value2);
  Matrix* matAns = new Matrix(2, 2, ans);
  
  REQUIRE(*matrixMul(mat1, mat2) == *matAns);
}


TEST_CASE("check matrix multiplication Larger", "[valgrind][weight=1]") {
// A = np.array([[1, 2, -3, 4], 
//              [1, 2, -3, -4],
//              [1, 2, -3, 4],
//              [1, 2, -3, 4]])
// B = np.array([[1, 2, -3, 4], 
//              [1, 2, -3, -4],
//              [1, 2, -3, 4],
//              [1, 2, -3, 4]])
  double ** value1;
  value1 = new double*[4];
  for (int i = 0; i < 5; i++) {
    value1[i] = new double[4];
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
  double ** value2;
  value2 = new double*[4];
  for (int i = 0; i < 4; i++) {
    value2[i] = new double[4];
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
  double ** ans;
  ans = new double*[4];
  for (int i = 0; i < 4; i++) {
    ans[i] = new double[4];
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
}

TEST_CASE("matrixEqual", "[valgrind][weight=1]") {
}