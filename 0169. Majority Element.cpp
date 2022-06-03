#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        //find the how large the count must be for the value to be the most common
        const int min_count_required = (nums.size()+1)/2; //round it up

        //get counts for all elements in `nums`
        for (const int& i : nums) {
            if (count.count(i)) {
                ++count.at(i);
            } else {
                count.emplace(i,1);
            }
            if (count.at(i) >= min_count_required) return i;
        }
    }
};


//V2, if you sort the array, the solution will always be in the middle It is quite fast... and O(1) (or O(n) if you can't modify the original.
#include <algorithm>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
