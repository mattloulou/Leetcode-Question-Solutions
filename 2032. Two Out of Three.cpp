#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        sort(nums1.begin(), nums1.end()); // MISTAKE: I originally forgot to sort the vectors before using std::unique on them.
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        auto end1 = unique(nums1.begin(), nums1.end());
        auto end2 = unique(nums2.begin(), nums2.end());
        auto end3 = unique(nums3.begin(), nums3.end());
        auto p1 = nums1.begin(), p2 = nums2.begin(), p3 = nums3.begin();

        unordered_map<int, int> numCounts; // {element, occurance count}

        for (; p1 != end1; ++p1) {
            ++numCounts[*p1];
        }
        for (; p2 != end2; ++p2) {
            ++numCounts[*p2];
        }
        for (; p3 != end3; ++p3) {
            ++numCounts[*p3];
        }

        vector<int> result;

        for (const auto& p : numCounts) {
            if (p.second >= 2) {
                result.push_back(p.first);
            }
        }

        return result;
    }
};