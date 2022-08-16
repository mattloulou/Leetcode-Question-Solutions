#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        uint32_t solution = UINT32_MAX; // we begin with the max value

        for (uint32_t i = (1u << 31); i >= 1; i>>=1) {
            solution ^= i; // set the ith bit to 0
            int sum = 0;
            for (const auto& n : nums) sum += n/solution + (n%solution != 0);
            if (sum > threshold) solution ^= i; // if we are over the threshold, solution has become too small, so undo the previous change to solution 
                                                // (set the bit back to 1)
            if (solution == 1) return 1; // Since 1 is the largest solution found so far, and our solution must be >=1, the final answer must be 1
        }

        return solution;
    }
};