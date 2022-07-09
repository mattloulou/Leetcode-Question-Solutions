#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int,int> inputs; //key is the value in nums, value is the index.
        for (int i = 0; i < nums.size(); ++i) {

            //check if the required matching value was already emplaced into inputs
            if (inputs.count(target - nums[i])) {
                answer.push_back(i);
                answer.push_back(inputs.at(target - nums[i]));
                return answer;

            //emplace into inputs key = nums.at(i), value = i 
            } else {
                inputs.emplace(nums[i], i);
            }
        }
        return answer;
    }
};