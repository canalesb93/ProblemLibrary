#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>

typedef std::vector<int> IntVector;
typedef std::pair<int, int> IntPair;
typedef std::set<IntPair> PairSet;
typedef std::unordered_map<int, PairSet> SumMap;

using namespace std;

void twoPairsSum(vector<int> ar){

    SumMap map;

    int i, j;
    for (i = 0; i < 7; ++i) {
        for (j = i+1; j < 7; ++j) {
            int sum = ar[i] + ar[j];
            map[sum].insert(IntPair(i, j));
        }
    }

    // Find pairs
    for (const auto &mit: map) {
        const PairSet &set = mit.second;
        PairSet::const_iterator sit, send;
        PairSet::const_iterator sit2;
        for (sit = set.begin(), send = set.end(); sit != send; ++sit) {
            for (sit2 = ++PairSet::const_iterator(sit); sit2 != send; ++sit2) {
                int A = sit->first;
                int B = sit->second;
                int C = sit2->first;
                int D = sit2->second;

                if (A != C and B != D) {
                    std::cout << "(" << A << ", "
                        << B << ", " << C
                        << ", " << D << ")\n";

                    return;
                }
            }
        }
    }
}


int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(0);
    arr.push_back(-1);
    twoPairsSum(arr);
    
    return 0;
}