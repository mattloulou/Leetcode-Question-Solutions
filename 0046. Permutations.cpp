#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int permutation_count = factorial(nums.size());
        vector<vector<int>> solution (permutation_count, vector<int>(nums.size()));

        for (const auto& num : nums) {

        }
    }

    int factorial(int n) const {
        int ret = 1;
        while (n > 1) {
            ret *= n--;
        }
        return ret;
    }
};