#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;


// didn't finish. It didn't pass all test cases. They were confusing :/.
class Solution {
public:

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> solution(queries.size());
        for (int query = 0; query < queries.size(); ++query) {
            vector<string> trimmedNums(nums.size());
            for (int i = 0; i < nums.size(); ++i) {
                trimmedNums[i] = nums[i].substr(nums[0].size()-queries[query][1]);
            }
            vector<string> trimmedNumsCopy(trimmedNums);
            sort(trimmedNumsCopy.begin(), trimmedNumsCopy.end());
            string strSolution = trimmedNumsCopy[queries[query][0]-1];
            for (int i = 0; i < trimmedNums.size(); ++i) {
                if (trimmedNums[i] == strSolution) {
                    solution[query] = i;
                    break;
                }
            }
        }
        return solution;
    }
};