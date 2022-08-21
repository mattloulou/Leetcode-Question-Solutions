#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> counts(10);
        for (const char& c : num) {
            ++counts[c-'0'];
        }

        string result;
        char middleChar = '\0'; // null char
        for (int i = 9; i >= 0; --i) {
            result += (result == "" && i == 0) ? "": string(counts[i]/2,'0'+i); // the condition is to prevent trailing 0s.
            if (middleChar == '\0' && counts[i]%2 == 1) middleChar = '0'+i;
        }

        if (result == "" && (middleChar == '\0' || middleChar == '0')) return "0"; // this will be the case when we only have 0s in num.

        if (middleChar != '\0') {
            return result + middleChar + string(result.rbegin(), result.rend());
        } else {
            return result + string(result.rbegin(), result.rend());
        }
    }
};

