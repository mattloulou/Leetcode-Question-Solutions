#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        vector<int> letter_count(26,0);

        for (const auto& c : s) {
            ++letter_count[c-'a'];
        }

        // sort all entries based on frequency. This is technically O(1) since there are only 26 letters >:)
        sort(letter_count.begin(), letter_count.end());

        int chars_to_remove = 0;
        for (int i = 0; i < 25; ++i){
            if (letter_count[i] == 0) continue;
            if (letter_count[i] == letter_count[i+1]) chars_to_remove += 1;
        }
        return chars_to_remove;
    }
};