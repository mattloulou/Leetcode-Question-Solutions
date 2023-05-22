#include <set>
#include <utility>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

    struct compare {
        bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const {
            return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> n;
        for (int i = 0; i < nums.size(); ++i) {
            n[nums[i]] += 1;
        } 

        set<pair<int, int>, compare> s;
        for (auto p : n) {
            s.insert({p.first, p.second});
        }

        vector<int> v;
        auto it = s.begin();
        for (int i = 0; i < min(k, static_cast<int>(s.size())); ++i, advance(it, 1)) {
            v.push_back(it->first);
        }

        return v;
    
    }
};