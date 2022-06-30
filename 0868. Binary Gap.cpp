#include <algorithm>
#include <iostream>
using namespace std;

//A nice O(popcount()) original solution : )
class Solution {
public:
    int binaryGap(int n) {
        int previousCtz = __builtin_ctz(n);
        int bestDistance = 0;
        while (n &= (n-1)) {
            int newCtz = __builtin_ctz(n);
            bestDistance = max(bestDistance, newCtz-previousCtz);
            previousCtz = newCtz;
        }
        return bestDistance;
    }
};