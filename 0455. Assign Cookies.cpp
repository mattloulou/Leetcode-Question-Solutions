#include <vector>
#include <algorithm>
using namespace std;

// V1 O(nlogn). I used the following discussion post to optimize my solution by a little bit (removed a duplicate variable):
// https://leetcode.com/problems/assign-cookies/discuss/93991/Easy-Understanding-C%2B%2B-solution-O(nlogn)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gIndex = 0;
        int sIndex = 0;
        while (gIndex < g.size() && sIndex < s.size()) {
            if (g[gIndex] <= s[sIndex]) {
                ++gIndex;
            }
            ++sIndex;
        }
        return gIndex;
    }
};