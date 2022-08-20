#include <vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;
        
        vector<int> values{0,1,1}; // {T0, T1, T2}
        for (int i = 2; i < n; ++i) {
            const int sum = values[0] + values[1] + values[2];
            values[0] = values[1];
            values[1] = values[2];
            values[2] = sum;
        }
        return values[2];

    }
};