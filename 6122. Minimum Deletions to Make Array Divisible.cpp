#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int numsDivideGcd = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); ++i) {
            numsDivideGcd = std::gcd(numsDivideGcd, numsDivide[i]);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (numsDivideGcd % nums[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};