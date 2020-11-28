#include "utils.h"
#include <sstream>

using std::stringstream;

namespace utils {
    vector<string> split(string &s, char delim) {
        vector<string> elems;
        _split(s, delim, elems);
        return elems;
    }

    void _split(string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }

    string strip(string& s) {
        return s.substr(1, s.size() - 2);
    }
}