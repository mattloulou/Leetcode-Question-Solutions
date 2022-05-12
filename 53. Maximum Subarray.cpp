#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 1) return nums.at(0);

        //PART 1: first, I want an array showing the continuous sum up until a point
        //we need to give the array an extra spot so we can have the first position always be 0.
        //If we don't do this, then my solution in PART 2 won't consider the first element properly.
        vector<int> running_sum(nums.size()); 
        running_sum.at(0) = nums.at(0);
        int largest_nums = nums.at(0);
        for (int i = 1; i < running_sum.size(); ++i) {
            running_sum.at(i) = running_sum.at(i-1) + nums.at(i);
            largest_nums = (nums.at(i) > largest_nums) ? nums.at(i): largest_nums;
        }

        //case where all nums are negative (part 2 solution won't work)
        if (largest_nums < 0) return largest_nums;

        //PART 2: now we mimic the solution from leetcode problem 121. Best Time to Buy and Sell Stock (solved it previously) to find the largest change
        //we iterate through the running_sum vector, and keep comparing the current value to the lowest value seen up until this point
        int max_subarray = nums.at(0); //the instructions say that a subarray must contain at least 1 number, so nums.at(0) will be the default. Unlike Q121, the default can't be 0.
        int min = 0;
        for (int i = 0; i < running_sum.size(); ++i) {
            min = (running_sum.at(i) < min) ? running_sum.at(i) : min;
            const int difference = running_sum.at(i) - min;
            max_subarray = (difference > max_subarray) ? difference : max_subarray;
        }

        return max_subarray;
    }

    //Hargun's Solution (much more ellegant and faster too):
    /*class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum = nums.at(0);
            int maxsum = sum;
            
            for(int i = 1; i < nums.size(); ++i){
                sum = max(nums.at(i), sum + nums.at(i));
                maxsum = max(maxsum, sum);            
            }
            return maxsum;
        }
    };*/
};