#include <vector>
#include <algorithm>
using namespace std;

//my IDE shows errors but leetcode takes it, and I think it is good too.
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        for (const auto& account : accounts) {
            max_wealth = max(std::move(max_wealth), std::accumulate(account.begin(), account.end(), 0));
        }
        return max_wealth;
    }
};