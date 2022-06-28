#include <vector>
#include <algorithm>
using namespace std;

// V1 O(nlogn) using sort()
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) return i;
        }

        // if we don't have a return in the for-loop, it means it has to be the last num
        return nums.size(); 
    }
};

// V2 O(n) using bit manipulation
// Solution: Basically, we will take 0, and xor it with every value in nums, and every value for [0, n]
// Every number will be xor'd twice (undoing it) except for the missing one, which is our answer 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result ^= nums[i];
            result ^= i;
        }
        result ^= nums.size(); // this is because the for only has `0 <= i < nums.size()` and we must include nums.size()
        return result;
    }
};

// V3 O(n) Hargun's solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int vectorSum = 0;
        for (const auto& n : nums) {
            vectorSum += n;
        }
        const int totalElements = nums.size() + 1;
        const int sumWithMissingNumber = nums.size()*totalElements/2; // the formula (first+last)*n/2
        return sumWithMissingNumber - vectorSum;
    }
};