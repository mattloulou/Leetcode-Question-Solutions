#include <string>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        bool inBarPair = false;
        int result = 0;
        for (const auto& c : s) {
            if (c == '|') {
                inBarPair = !inBarPair;
                continue;
            }
            if (!inBarPair && c == '*') ++result;
        }
        return result;
    }
};