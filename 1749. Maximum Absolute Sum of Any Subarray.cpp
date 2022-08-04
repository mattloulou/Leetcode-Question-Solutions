#include <vector>
using namespace std;

// It is basically like finding the max subarray, but you will instead keep track of the max (most positive) and min (most negative) subarrays.
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int result = abs(nums[0]);
        int greedyPositive = nums[0]; // we want the most-positive subarray
        int greedyNegative = nums[0]; // we want the most-negative subarray

        for (int i = 1; i < nums.size(); ++i) {
            greedyPositive = max(greedyPositive + nums[i], nums[i]);
            greedyNegative = min(greedyNegative + nums[i], nums[i]);
            result = max(result, max(greedyPositive, abs(greedyNegative)));
        }

        return result;
    }
};