#include <iostream>
#include <chrono>
#include <vector>
#include <functional>
#include <algorithm>
#include "utils.hpp"
using namespace std;


void printVec(const vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

// measure total run time in ms
double benchmark(function<void(vector<int>&)> sortFunc, unsigned int seed, int elementCount) {
    vector<int> v(elementCount);

    srand(seed);
    for (int i = 0; i < elementCount; i++) {
        v.push_back(rand() % 10000);
    }

    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    
    // begin measurement
    auto t_start = chrono::high_resolution_clock::now();
    sortFunc(v);
    auto t_end = chrono::high_resolution_clock::now();
    if (v != sorted) {
        cout << "Invalid sorted array. Exiting." << endl;
        cout << "Expected:" << endl;
        printVec(sorted);
        cout << "Got:" << endl;
        printVec(v);
        exit(1);
    } 

    return std::chrono::duration<double, std::milli>(t_end-t_start).count();
}

