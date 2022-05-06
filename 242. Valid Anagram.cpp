#include <string>
#include <map>

using namespace std;
class Solution {
public:
    //promised to only be lowercase english letters
    bool isAnagram(string s, string t) {
        int char_count[26]{0};
        for (const char& c : s) {
            ++char_count[c-'a'];
        }
        for (const char& c : t) {
            --char_count[c-'a'];
        }
        for (const int& i : char_count) {
            if (i != 0) return false;
        }
        return true;
    }
};