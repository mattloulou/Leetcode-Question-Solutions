#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_set<int> intersecting_values;
        unordered_set<int> new_intersecting_values;
        for (const int& num : nums[0]) {
            intersecting_values.insert(num);
        }     

        

        for (int i = 1; i < nums.size(); ++i) {
            for (const int& num : nums[i]) {
                if (intersecting_values.count(num)) new_intersecting_values.insert(num);
            }
            intersecting_values = std::move(new_intersecting_values);
            new_intersecting_values.clear();
        }

        // now put the set into a sorted vector
        vector<int> result{};
        for (auto it = intersecting_values.begin(); it != intersecting_values.end(); ++it) {
            result.push_back(*it);
        }
        sort(result.begin(), result.end());
        return result;
    }
};