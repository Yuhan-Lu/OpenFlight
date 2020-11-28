#include "airlines.h"
#include <fstream>  
#include <iostream>
#include <map>

using namespace std;
// constructor of airlines
airlines::airlines(int airlineID, string name, string alias, string IATA, 
        string ICAO, string callsign, string country, string active) {
            
    this->airlineID = airlineID;  
    this->name = name;  
    this->alias = alias;  
    this->IATA = IATA;  
    this->ICAO = ICAO;  
    this->callsign = callsign;  
    this->country = country;  
    this->active = active;        
    
}

map<int, airlines> loadData(string  fileName) {
    map<int, airlines> airlinesDAT; 
    ifstream infile(fileName);  
    
    string line;
    // handle error
    if (!infile.is_open()) {  
        cout << "can not open the file \n"<<endl;
        return;
    }
    // loop through dat by lines
    while(getline(infile,line)) {  
        //cout << line << "\n";
        
        //compiler error stupid bug exist
        vector<string> lineVec = split(line, ",");
        
        cout << "test" << lineVec[0] >> endl;
        
        
        airlines eachRow = new airlines(to_integer(lineVec[0]), lineVec[1], lineVec[2], lineVec[3], lineVec[4], 
        lineVec[5], lineVec[6], lineVec[7]);
        airlinesDAT[to_integer(lineVec[0])] = eachRow;
    }
    infile.close();
    return airlinesDAT;
}

void airlines::_split(string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
vector<string> airlines::split(string &s, char delim) {
    vector<string> elems;
    _split(s, delim, elems);
    return elems;
}