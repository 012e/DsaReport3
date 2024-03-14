#include <vector>
using namespace std;

void interchangeSort(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}
