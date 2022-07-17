#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> counts;
        for (const auto& num : nums) {
            ++counts[num];
        }
        vector<int> result(2);
        for (const pair<int,int>& p : counts) {
            result[0] += p.second/2;
            result[1] += p.second % 2;
        }
        return result;
    }
};