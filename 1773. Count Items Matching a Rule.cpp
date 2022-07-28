#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int itemsIndex = 0;
        if (ruleKey[0] == 'c') {
            itemsIndex = 1;
        } else if (ruleKey[0] == 'n') {
            itemsIndex = 2;
        }

        int answer = 0;
        for (const vector<string>& item : items) {
            if (item[itemsIndex] == ruleValue) ++answer;
        }      
        return answer;
    }
};

// V2 2-line solution https://leetcode.com/problems/count-items-matching-a-rule/discuss/1086218/C%2B%2B-2-liner-(count_if)
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        const int index = (ruleKey[0] == 't') ? 0 : ((ruleKey[0] == 'c') ? 1 : 2);
        return count_if(items.begin(), items.end(), [&](const auto& i){return i[index] == ruleValue;});
    }
};