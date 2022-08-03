#include <vector>
#include <set>
using namespace std;

// V1 (Fails in situations like: "2 0 1")
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> solution(nums.size());

        // start at the second last number
        for (int i = nums.size()-2; i >= 0; --i) {
            const int& targetNum = nums[i];

            // find the first number smaller than nums[i], which will tell us 
            // If nothing is found by the end of the for loop, nums[i] will remain at 0 (default value in the vector)
            // This makes sense, as it means there is nothing smaller than it after it
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[j] < targetNum) {
                    solution[i] = solution[j] + 1;
                    break;
                }
            }
        }

        return solution;
    }
};
