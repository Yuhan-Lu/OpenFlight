#include <iostream>
#include <map>
#include "airlines.h"
#include "airports.h"
#include "routes.h"
#include "planes.h"

using std::cout;
using std::endl;

int main() {

    Airlines airlinesDAT;
    Airports airportDAT;
    //cout << airlinesDAT.getAirlineByID(1)->alias <<endl;
    cout << airportDAT.getAirportByID(507)->latit << endl;

    return 0;
}