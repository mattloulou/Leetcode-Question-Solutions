#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = std::accumulate(nums.begin(), nums.end(), 0) - nums[0];
        int leftSum = 0;
        int index = 0;
        while (true) {
            if (leftSum == rightSum) {
                return index;
            } else if (index == nums.size()-1) break;
            leftSum += nums[index];
            rightSum -= nums[index+1];
            ++index;
        }
        return -1;
    }
};