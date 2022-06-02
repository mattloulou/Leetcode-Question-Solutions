#include <string> 
#include <unordered_set>
using namespace std;

//V1 solution. Super fast but memory tradeoff (compared to doing O(nk) comparisons, where n = jewels.size() and k = stones.size())
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewel_set(jewels.begin(), jewels.end());
        int result = 0;
        for (const char& c : stones) {
            if (jewel_set.count(c)) ++result;
        }
        return result;
    }
};