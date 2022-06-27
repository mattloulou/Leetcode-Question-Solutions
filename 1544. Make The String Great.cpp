#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        vector<int> indicesToRemove;
        int i = 0;
        while (i < s.size()) {

            // if the letters are matching:
            if (s[i] == s[i+1] + ('A'-'a') || s[i] == s[i+1] - ('A'-'a')) {
                s.erase(i,2);
                if (i > 0) {
                    i -= 1; // put `i` down one for the next iteration to reassess if a new bad combo was created
                }

            // if the neighbouring letters are not matching:                  
            } else {
                ++i;
            }
        }
        return s;
    }
};