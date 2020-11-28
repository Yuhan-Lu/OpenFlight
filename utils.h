#pragma once
#include <vector>
#include <string>

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
}