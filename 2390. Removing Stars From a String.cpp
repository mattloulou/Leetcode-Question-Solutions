#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int starCount = 0;
        string reverseResult;
        for (auto c = s.rbegin(); c != s.rend(); ++c) {
            if (*c == '*') {
                ++starCount;
            } else {
                if (starCount) {
                    --starCount;
                } else {
                    reverseResult.push_back(std::move(*c));
                }
            }
        }
        return string(reverseResult.rbegin(), reverseResult.rend());
    }
};