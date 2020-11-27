
#include <iostream>
#include <map>
#include "airlines.h"
#include "airlines.cpp"

using namespace std;

int main() {
    
    map<int, airlines> airlinesDAT; 
    airlinesDAT = loadData("airlines.dat");

    return 0;
}