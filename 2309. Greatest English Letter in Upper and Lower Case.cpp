#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> chars;
        for (const char& c : s) {
            chars.insert(c);
        }
        for (char c = 'Z'; c >= 'A'; --c) {
            if (chars.count(c) && chars.count(c+32)) return string(1, c);
        }     
        return "";
    }
};