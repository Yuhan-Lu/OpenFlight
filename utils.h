#pragma once
#include <vector>
#include <string>
#include <math.h>

using std::vector;
using std::string;

namespace utils {
    /**
     * Split the given string with the specified delimiter
     * @param s input string
     * @param delim the specified delimiter
     * @returns a vector that contains all the entries
     */
    vector<string> split(string &s, char delim);

    /**
     * Helper function of the split function
     * @param s input string
     * @param delim the specified delimiter
     * @param elems a vector that contains all the entries
     */
    void _split(string &s, char delim, vector<string> &elems);

    /**
     * Strip all the quotation marks in the string
     */
    string strip(string &s);

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
}