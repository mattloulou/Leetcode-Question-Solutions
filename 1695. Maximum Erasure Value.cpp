#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> visited_numbers;
        int max_size = 0;
        int current_streak = 0;
        int current_streak_starting_index = 0;

        for (int i = 0; i < nums.size(); ++i) {
            
            // if the number can be included in this streak
            if (visited_numbers.count(nums[i]) == 0 || visited_numbers.at(nums[i]) < current_streak_starting_index) {
                current_streak += nums[i];
                max_size = max(max_size, current_streak);
            
            // otherwise, we need to change the size of the current streak and update the starting index.
            } else {
                for (int j = current_streak_starting_index; j < visited_numbers.at(nums[i]); ++j) {
                    current_streak -= nums[j];
                } 
                current_streak_starting_index = visited_numbers.at(nums[i]) + 1;
            }
            // update the last-seen-index.
            visited_numbers[nums[i]] = i;
        }

        return max_size;
    }
};