#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans(queries.size());
        
        for (int i = 0; i < queries.size(); ++i) {
            int subSequenceSize = 0;
            int sum = 0;
            for (; subSequenceSize < nums.size(); ++subSequenceSize) {
                if (sum + nums[subSequenceSize] <= queries[i]) {
                    sum += nums[subSequenceSize];
                } else {
                    break;
                }
            }
            
            ans[i] = subSequenceSize;
        }
        
        
        return ans;
    }
};