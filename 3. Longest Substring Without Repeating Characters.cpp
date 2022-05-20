#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index_last_seen(128,-1); //needs all alphanumeric + symbols + spaces? So I will give it 0-127 in ASCII.
        int current_streak = 0;
        int max_streak = 0;
        int current_streak_starting_index = 0;

        //loop through all chars
        for (int i = 0; i < s.length(); ++i) {

            //if the current char is not within the current streak
            if (index_last_seen[s.at(i)] < current_streak_starting_index) {
                ++current_streak;
                max_streak = max(current_streak, max_streak);

            //the current char is within the current streak --> find the length of the new streak && update last seen index
            } else {
                current_streak_starting_index = index_last_seen[s.at(i)] + 1;
                current_streak = i-index_last_seen[s.at(i)];  
            }

            index_last_seen[s.at(i)] = i;
            
        }
        return max_streak;

    }
};