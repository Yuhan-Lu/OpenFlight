#pragma once
#include <vector>
#include <string>
#include <math.h>

using std::vector;
using std::string;

namespace utils {
    /**
     * Prepare the raw string for inputing data
     * @param s input string
     * @returns a vector that contains all the entries
     */
    vector<string> readEntry(string &s);

    /**
     * Get the distance between two points on earth given their latitude and
     * longtitude. 
     * @param latitude1 latitude of the first point
     * @param longtitude1 longtitude of the first point
     * @param latitude2 latitude of the second point
     * @param longtitude2 longtitude of the second point
     * @returns distance between these two points
     */
    double getDistance(double latitude1, double longtitude1, double latitude2, double longtitude2);

    const static int ERROR_AIRPORT_ID = -pow(2,30);
}