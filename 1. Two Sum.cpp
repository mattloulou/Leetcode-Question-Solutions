#include <vector>
#include <unordered_map>
using namespace std;

//V1.0

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> answer;
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 if (nums.at(i) + nums.at(j) == target) {
//                     answer.emplace_back(i);
//                     answer.emplace_back(j);
//                     return answer;
//                 } 
//             }
//         }
//         return answer;
//     }
// };


//V2.0

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int,int> inputs; //key is the value in nums, value is the index.
        for (int i = 0; i < nums.size(); ++i) {

            //check if the required matching value was already emplaced into inputs
            if (inputs.count(target - nums.at(i))) {
                answer.push_back(i);
                answer.push_back(inputs.at(target - nums.at(i)));
                return answer;

            //emplace into inputs key = nums.at(i), value = i 
            } else {
                inputs.emplace(nums.at(i), i);
            }
        }
        return answer;
    }
};