#include <ctime>
#include <chrono>
#include <vector>
#include <functional>
using namespace std;

double benchmark(function<void(vector<int>&)>, unsigned int, int);
