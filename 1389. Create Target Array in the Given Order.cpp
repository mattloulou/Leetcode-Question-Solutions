#include <vector>
using namespace std;
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target{};
        target.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            target.insert(target.begin() + index[i], nums[i]);
        }
        return target;
    }
};