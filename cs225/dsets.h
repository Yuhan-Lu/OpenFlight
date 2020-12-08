#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

template <typename T>
class DisjointSets {
    public:
        /**
         * Creates one unconnected root node at the end of the vector.
         * @param ele the element needed to be added to the disjoint set
         */
        void addElement(T ele);

        /**
         * Find the representative number of the set where elem belongs, compress the size along 
         * with find
         * @param a	First element to union
         * @param b	Second element to union
         * @returns whether the two elements are in one set
         */
        bool inSameSet(T a, T b);
        
        /**
         * Union two sets, union-by-size.
         * @param a	First element to union
         * @param b	Second element to union
         */
        void setUnion(T a, T b);
        
        /**
         * Return the number of nodes in the up-tree containing the element.
         * @returns number of nodes in the up-tree containing the element
         */
        int size(int elem);

        void printStatusReport() {
            cout << "#-------- Disjoint Set Status Report" << endl;
            cout << "Ele\t\t" << "Idx" << endl; 
            for (auto it = _innerMapping.begin(); it != _innerMapping.end(); ++it) {
                auto pair = *it;
                cout << pair.first << "\t->\t" << pair.second << endl;
            }
            vector<std::pair<int,int>> res;
            cout << "Storage space" << endl;
            cout << "Idx\t" << "Root" << endl;
            for (size_t i = 0; i < _storage.size(); i++) {
                cout << i << "\t" << _storage[i] << endl;;
                if (_storage[i] < 0)
                    res.push_back(std::pair<int, int>(i, -_storage[i]));
            }
            cout << "Nodes" << endl;
            cout << "Idx\t\t" << "Count" << endl;
            for (auto it = res.begin(); it != res.end(); ++it) {
                auto pair = *it;
                cout << pair.first << "\t->\t" << pair.second << endl;
            }
            cout << "#-------- End Disjoint Set Status Report" << endl;
        }

    private:
        /**
         * Find the representative number of the set where elem belongs, compress the size along 
         * with find
         * @param elem the element wanted to be found
         * @returns the index of the root of the up-tree in which the parameter element resides
         */
        int _find(int elem);

        /* Internal storage */
        vector<int> _storage;

        /* Interface coupling with input */
        unordered_map<T, int> _innerMapping;
};