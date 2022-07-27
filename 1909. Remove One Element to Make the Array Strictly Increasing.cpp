#include <vector>
using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        bool erasedNumber = false;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i+1] <= nums[i]) {

                // see if we can remove nums[i], or nums[i+1]
                if (erasedNumber) return false;                    

                // try removing nums[i]
                if (i == 0 || nums[i+1] > nums[i-1]) {
                    erasedNumber = true;
                    continue;
                }

                // try removing nums[i+1]
                if (i+1 == nums.size()-1 || nums[i+2] > nums[i]) {
                    erasedNumber = true;
                    ++i;
                    continue;
                }

                return false;

            }
        }      
        return true;
    }
};