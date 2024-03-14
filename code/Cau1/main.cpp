#include <iostream>
#include <iomanip>
#include <functional>
#include "utils.hpp"

#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "insertionSort.hpp"
#include "interchangeSort.hpp"

using namespace std;
void runAndReport(function<void(vector<int>&)> sortFun, const vector<int>& arraySizes, string sortName) {
    for (int arraySize : arraySizes){
        double total = 0;
        cout << "Thuat toan: " << sortName << "\n";
        printf("So luong phan tu: %d\n", arraySize);
        for (int i = 0; i < 5; ++i) {
            double runTime = benchmark(sortFun, 696969696 + 69 * i, arraySize);
            total += runTime;
            cout << setprecision(17) << runTime << "ms" << endl;
        }
        // cout << "Toc do chay trung binh: " << setprecision(17) << total / 5 << "ms" << endl;
        // cout << "--------------------------\n";
    }
}

int main() {
    auto arraySizes = vector<int>{100, 500, 1000, 5000, 10000};
    runAndReport(interchangeSort, arraySizes, "interchange sort"s);
    runAndReport(insertionSort, arraySizes, "insertion sort"s);
    runAndReport(bubbleSort, arraySizes, "bubble sort"s);
    runAndReport(selectionSort, arraySizes, "selection sort"s);
}
