#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const int n = nums.size();
        vector<int> output(n*2);
        for (int i = 0; i < n; ++i) {
            output[i] = nums[i];
            output[i+n] = nums[i];
        }
        return output;
    }
};