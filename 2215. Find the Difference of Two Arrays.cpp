#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numsFirst(nums1.begin(), nums1.end());
        unordered_set<int> numsSecond(nums2.begin(), nums2.end());
        vector<vector<int>> result(2);
        for (const auto& n : numsFirst) {
            if (!numsSecond.count(n)) result[0].push_back(n);
        }
        for (const auto& n : numsSecond) {
            if (!numsFirst.count(n)) result[1].push_back(n);
        }
        return result;
    }
};