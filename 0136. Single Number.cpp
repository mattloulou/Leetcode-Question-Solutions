#include <vector>
using namespace std;

// O(n). Solution: Every number which appears twice, will have no effect on `result`, as the second XOR with it will
// undo the first. Thus, only the number with a single occurance will remain in result.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const int& num : nums) {
            result ^= num;
        }
        return result;
    }
};