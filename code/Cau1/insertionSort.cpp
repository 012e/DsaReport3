#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int j = i;
        while (j > 0 && v[j] < v[j-1]) {
            swap(v[j], v[j-1]);
            j--;
        }
    }
}
