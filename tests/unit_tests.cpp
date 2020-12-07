#include "../cs225/catch/catch.hpp"

#include "../airlines.h"
#include "../airports.h"
#include "../planes.h"
#include "../routes.h"
#include "../utils.h"
#include "../pagerank.h"
#include <iostream>
#include <map>

using namespace utils;

TEST_CASE("check the Airlines constructor and getAirlineByID.", "[valgrind][weight=1]") {
  Airlines airlines(true);
  REQUIRE(airlines.getAirlineByID(2)->name == "135 Airways");
  REQUIRE(airlines.getAirlineByID(2)->alias.size() == 0);
  REQUIRE(airlines.getAirlineByID(2)->IATA.size() == 0);
  REQUIRE(airlines.getAirlineByID(2)->ICAO == "GNL");
  REQUIRE(airlines.getAirlineByID(2)->callsign == "GENERAL");
  REQUIRE(airlines.getAirlineByID(2)->country == "United States");
  REQUIRE(airlines.getAirlineByID(2)->active == false);

}

TEST_CASE("check some random cases of getAirlineByID.", "[valgrind][weight=1]") {
  Airlines airlines(true);
  REQUIRE(airlines.getAirlineByID(563)->country == "Germany");
  REQUIRE(airlines.getAirlineByID(125)->IATA == "FG");
  REQUIRE(airlines.getAirlineByID(781)->ICAO == "CRP");
  REQUIRE(airlines.getAirlineByID(-1)->callsign.size() == 0);
}

TEST_CASE("check the Airports constructor and getAirportByID.", "[valgrind][weight=1]") {
  Airports airports(true);
  REQUIRE(airports.getAirportByID(1)->name == "Goroka Airport");
  REQUIRE(airports.getAirportByID(1)->city == "Goroka");
  REQUIRE(airports.getAirportByID(1)->country == "Papua New Guinea");
  REQUIRE(airports.getAirportByID(1)->IATA == "GKA");
  REQUIRE(airports.getAirportByID(1)->ICAO == "AYGA");
  REQUIRE(airports.getAirportByID(1)->latit == -6.081689834590001);
  REQUIRE(airports.getAirportByID(1)->longit == 145.391998291);
  REQUIRE(airports.getAirportByID(1)->alt == 5282);
}

TEST_CASE("check some random cases of getAirportByID.", "[valgrind][weight=1]") {
  Airports airports(true);
  REQUIRE(airports.getAirportByID(12076)->latit == 39.602194);
  REQUIRE(airports.getAirportByID(150)->longit == -105.262001038);
  REQUIRE(airports.getAirportByID(641)->name == "Harstad/Narvik Airport, Evenes");
  REQUIRE(airports.getAirportByID(6275)->IATA == "HGD");
}

TEST_CASE("check getAirportByIATA.", "[valgrind][weight=1]") {
  Airports airports(true);
  REQUIRE(airports.getAirportIDByIATA("MAG") == 2);
  REQUIRE(airports.getAirportIDByIATA("HGU") == 3);
}

TEST_CASE("check getPlaneByIATA.", "[valgrind][weight=1]") {
  Planes planes(true);
  REQUIRE(planes.getPlaneByIATA("ND2")->name == "Aerospatiale (Nord) 262");
}

TEST_CASE("check constructor of routes.cpp.", "[valgrind][weight=1]") {
  Routes routes(false);
  Routes::RoutesNode* begin = *(routes.begin()); 
  //std::cout << begin->equipment << std::endl;
  REQUIRE(begin->airline == "2B");
  REQUIRE(begin->airlineID == 410);
  REQUIRE(begin->airport1 == "AER");
  REQUIRE(begin->airportID1 == 2965);
  REQUIRE(begin->airport2 == "KZN");
  REQUIRE(begin->airportID2 == 2990);
  REQUIRE(begin->codeshare == false);
  REQUIRE(begin->stops == 0);
  //REQUIRE(begin->equipment == "CR2");
}

TEST_CASE("check matrix multiplication", "[valgrind][weight=1]") {
  //{ { 2.0, -1.0}, { -1, 1}};
  double ** value1;
  value1 = new double*[2];
  for (int i = 0; i < 2; i++) {
    value1[i] = new double[2];
  }
  value1[0][0] = 2.0;
  value1[0][1] = -1.0;
  value1[1][0] = -1.0;
  value1[1][1] = 1.0;
  //{ { 2.0, -1.0}, { -1, 1}};
  double ** value2;
  value2 = new double*[2];
  for (int i = 0; i < 2; i++) {
    value2[i] = new double[2];
  }
  value2[0][0] = 1.0;
  value2[0][1] = 3.0;
  value2[1][0] = 1.0;
  value2[1][1] = 1.0;
  
  Pagerank::Matrix *mat1 = new Pagerank::Matrix(value1, 2, 2);
  Pagerank::Matrix *mat2 = new Pagerank::Matrix(value2, 2, 2);
  double ** res = (utils::matrixMul(mat1, mat2))->_value;
  
  REQUIRE(res[0][0] == 1);
  REQUIRE(res[0][1] == 5);
  REQUIRE(res[1][0] == 0);
  REQUIRE(res[1][1] == -2);
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
  
  Pagerank::Matrix *mat1 = new Pagerank::Matrix(value1, 4, 4);
  Pagerank::Matrix *mat2 = new Pagerank::Matrix(value2, 4, 4);
  double ** res = (utils::matrixMul(mat1, mat2))->_valuegit;
  
  REQUIRE(res[0][0] == 4);
  REQUIRE(res[0][1] == 8);
  REQUIRE(res[0][2] == -12);
  REQUIRE(res[0][3] == 0);
  REQUIRE(res[1][0] == -4);
  REQUIRE(res[1][1] == -8);
  REQUIRE(res[1][2] == 12);
  REQUIRE(res[1][3] == -32);
  REQUIRE(res[2][0] == 4);
  REQUIRE(res[2][1] == 8);
  REQUIRE(res[2][2] == -12);
  REQUIRE(res[2][3] == 0);
  REQUIRE(res[3][0] == 4);
  REQUIRE(res[3][1] == 8);
  REQUIRE(res[3][2] == -12);
  REQUIRE(res[3][3] == 0);
}
