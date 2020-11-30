
#include <iostream>
#include <map>
#include "airlines.h"
#include "airlines.cpp"
#include "airports.h"
#include "airports.cpp"

using namespace std;

int main() {
    
    Airlines airlinesDAT;
    airlinesDAT.init();
    Airports airportDAT;
    airportDAT.init();
    //cout << airlinesDAT.getAirlineByID(1)->alias <<endl;
    cout << airportDAT.getAirportByID(507)->latit << endl;

    return 0;
}