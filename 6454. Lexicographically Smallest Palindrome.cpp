#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int i = 0; i < s.length()/2; ++i) {
            const char newVal = std::min(s[i], s[s.length()-1-i]);
            s[i] = newVal;
            s[s.length()-1-i] = newVal;
        }
        return s;
    }
};