#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<vector<int>> letterCounts{}; // stores the count of each lowercase letter for each word in `words`
        vector<string> result{words[0]}; // begin the result vector with just the first word so far.
        if (words.size() > 1) {
            letterCounts.push_back(vector<int>(26));
            populateLetterCount(words[0], letterCounts.back());
        }

        for (int i = 1; i < words.size(); ++i) {

            // if they are different sizes, then they definitely must not be anagrams.
            if (words[i].size() != result.back().size()) {
                result.push_back(words[i]);
                continue;
            } else {

                // definitely anagram
                if (words[i] == result.back()) {
                    continue;
                }

                // get the count of the current word
                letterCounts.push_back(vector<int>(26));
                populateLetterCount(words[i], letterCounts.back());

                // check if they don't match
                for (int j = 0; j < 26; ++j) {
                    if (letterCounts[letterCounts.size()-2][j] != letterCounts.back()[j]) {
                        result.push_back(words[i]);
                        continue;
                    }
                }

                // if they do match, do nothing.

            }
        }
        return result;
    }


    void populateLetterCount(string& word, vector<int>& letterCounts) {
        for (const char& c : word) {
            ++letterCounts[c-'a'];
        }
    }
};