#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> last_seen(26,-1); // question says only lower case English letters

        for (int i = 0; i < s.size(); ++i) {
            int index = s[i] - 'a';

            // if it was seen before, then we set the index to INT_MAX.
            last_seen[index] = (last_seen[index] == -1) ? i: INT_MAX; 
        }

        int minimum_last_seen = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (last_seen[i] != -1) minimum_last_seen = min(minimum_last_seen, last_seen[i]);
        }
        return (minimum_last_seen != INT_MAX) ? minimum_last_seen: -1;
    }
};