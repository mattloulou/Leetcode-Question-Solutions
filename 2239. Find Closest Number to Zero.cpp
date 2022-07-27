#include <vector>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (abs(result) > abs(nums[i])) {
                result = nums[i];
            } else if (abs(result) == abs(nums[i])) {
                result = max(result, nums[i]);
            }
        }
        return result;
    }
};