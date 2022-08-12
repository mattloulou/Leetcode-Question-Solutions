#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), Comparator());
        return arr;    
    }

private:

    // note that for Comparators, return true if lhs should go before rhs.
    struct Comparator {
        bool operator() (const int& lhs, const int& rhs) const {
            if (__builtin_popcount(lhs) == __builtin_popcount(rhs)) {
                return lhs < rhs;
            } else {
                return __builtin_popcount(lhs) < __builtin_popcount(rhs);
            }
        }
    };
};