#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        unordered_set<string> passingWords;
        unordered_set<string> failedWords;
        for (const string& word : words) {
            if (failedWords.count(word)) continue;
            if (passingWords.count(word) || isSubsequence(s, word)) {
                passingWords.insert(word);
                ++result;
            } else {
                failedWords.insert(word);
            }
        }
        return result; // can't just return passingWords.size(), since we might have duplicate passing elements in `words`
    }

    // checks if word is a subsequence of s
    bool isSubsequence(const string& s, const string& word) const {
        int sIndex = 0;
        for (const char& c : word) {

            // keep searching until s[sIndex] matches c
            while (sIndex < s.size() && s[sIndex] != c) ++sIndex;

            // if we have run out of chars in s, then word is not a subsequence of s.
            if (sIndex >= s.size()) return false;
            ++sIndex;
        }
        return true;
    }
};