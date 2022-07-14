#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sCount(26,0);
        for (const char& c : s) {
            ++sCount[c-'a'];
        }
        for (const char& c : t) {
            --sCount[c-'a'];
            if (sCount[c-'a'] < 0) return c;
        }
        return 0; // shouldn't ever return here with valid inputs.
    }
};

//V2 using bit manip
class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (const char& c : s) {
            result ^= c;
        }
        for (const char& c : t) {
            result ^= c;
        }
        return result; // shouldn't ever return here with valid inputs.
    }
};