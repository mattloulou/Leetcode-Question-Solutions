#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int result = 0;
        int totalRemoved = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > totalRemoved) {
                totalRemoved = nums[i];
                ++result;
            }
        }

        return result;
    }
};