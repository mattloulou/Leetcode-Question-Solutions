#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> visited;
        for (int i = 0; i < nums.size(); ++i) {
            if (visited.count(nums[i])) {
                if (i - visited[nums[i]] <= k) return true;
            }
            visited[nums[i]] = i;
        }        
        return false;
    }
};