#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// V1: runtime efficient    
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_set<int> visitedOnce, visitedTwice;
        int sum = 0;
        for (const int& n : nums) {
            if (visitedOnce.count(n)) {
                sum -= n;
                visitedTwice.insert(n);
                visitedOnce.erase(n);
            } else if (!visitedTwice.count(n)) {
                sum += n;
                visitedOnce.insert(n);
            }
        }
        return sum;
    }
};