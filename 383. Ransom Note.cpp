#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        //we begin by finding what resources our ransomNote has to work with (take the count of all chars in the magazine)
        int char_counts[26]{0}; //MISTAKE: at first I did an array of chars, but then I realized it should be an array of ints because it is the char COUNT
        for (const char& c : magazine) {
            ++char_counts[c-'a'];
        }

        //now loop through magazine and make sure we have enough chars
        for (const char& c : ransomNote) {
            if (char_counts[c-'a'] < 1) return false;
            --char_counts[c-'a'];
        }
        return true;
    }
};