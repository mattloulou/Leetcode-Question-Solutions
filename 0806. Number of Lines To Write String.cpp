#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int currentWidth = 0;
        int numLines = 1;
        for (const char& c : s) {
            if (currentWidth + widths[c-'a'] > 100) {
                currentWidth = widths[c-'a'];
                ++numLines;
            } else {
                currentWidth += widths[c-'a'];
            }
        }
        return vector<int>{numLines, currentWidth};
    }
};