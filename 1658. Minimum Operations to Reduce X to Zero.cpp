#include <vector>
#include <queue>
#include <iostream>
using namespace std;

//V1 Too slow. Gets TLE
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (x == 0) return 0;

        queue<pair<int, pair<int,int>>> possible_sums; // {current_sum, {left_index, right_index}}. the indices refer to the left and right index in nums.
        possible_sums.push({x, {0, nums.size()-1}});
        while (!possible_sums.empty()) {
            auto queue_top = possible_sums.front();
            possible_sums.pop();
            
            const int& previous_sum = queue_top.first;
            const int& left_index = queue_top.second.first;
            const int& right_index = queue_top.second.second;

            // if we can subtract the left or right values then do so
            if (previous_sum == nums[left_index] || previous_sum == nums[right_index]) {
                return left_index + ((nums.size()-1) - right_index) + 1; // this is the number of operations it took
            }

            // if the left and right indices are the same, then that means there is only one value left to subtract. 
            // However, in the if-statement above, we already check if that last remaining value can get the sum to 0.
            // So, will not add anything to the queue in that case
            if (left_index == right_index) continue;

            // since we didn't get the sum to 0, we add the different possibilities to the queue
            const int sum_after_subtracting_left = previous_sum - nums[left_index];
            const int sum_after_subtracting_right = previous_sum - nums[right_index];
            if (sum_after_subtracting_left > 0) {
                possible_sums.push({sum_after_subtracting_left, {left_index + 1, right_index}});
            }
            if (sum_after_subtracting_right > 0) {
                possible_sums.push({sum_after_subtracting_right, {left_index, right_index - 1}});
            }
        }    
        
        return -1;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (x == 0) return 0;

        queue<pair<int, pair<int,int>>> possible_sums; // {current_sum, {left_index, right_index}}. the indices refer to the left and right index in nums.
        possible_sums.push({x, {0, nums.size()-1}});
        while (!possible_sums.empty()) {
            auto queue_top = possible_sums.front();
            possible_sums.pop();
            
            const int& previous_sum = queue_top.first;
            const int& left_index = queue_top.second.first;
            const int& right_index = queue_top.second.second;

            // if we can subtract the left or right values then do so
            if (previous_sum == nums[left_index] || previous_sum == nums[right_index]) {
                return left_index + ((nums.size()-1) - right_index) + 1; // this is the number of operations it took
            }

            // if the left and right indices are the same, then that means there is only one value left to subtract. 
            // However, in the if-statement above, we already check if that last remaining value can get the sum to 0.
            // So, will not add anything to the queue in that case
            if (left_index == right_index) continue;

            // since we didn't get the sum to 0, we add the different possibilities to the queue
            const int sum_after_subtracting_left = previous_sum - nums[left_index];
            const int sum_after_subtracting_right = previous_sum - nums[right_index];
            if (sum_after_subtracting_left > 0) {
                possible_sums.push({sum_after_subtracting_left, {left_index + 1, right_index}});
            }
            if (sum_after_subtracting_right > 0) {
                possible_sums.push({sum_after_subtracting_right, {left_index, right_index - 1}});
            }
        }    
        
        return -1;
    }
};