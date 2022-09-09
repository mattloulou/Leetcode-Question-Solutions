#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            if (isSelfDividing(i)) ans.push_back(i);
        }
        return ans;
    }
    
    bool isSelfDividing(int n) {
        int copy = n;
        while (copy) {
            const int digit = copy % 10;
            if (digit == 0 || n%digit != 0) return false;
            copy /= 10;
        }
        return true;
    }
};