#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> running_sums(nums.size(),0);
        if (nums.size() == 0) return running_sums;

        running_sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            running_sums[i] = running_sums[i-1] + nums[i];
        }
        return running_sums;
    }
};