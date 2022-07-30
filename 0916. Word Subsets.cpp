#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        // Since all words in words2 must be subsets of each individual word in words1, we just need to find the max frequency of each char in any one word in words 2.
        vector<int> words2MaxCharCount(26);
        for (const string& word : words2) {

            // collect the char count
            vector<int> currentWordCount(26);
            for (const char& c : word) {
                ++currentWordCount[c-'a'];
            }

            // compare it with max counts
            for (int i = 0; i < 26; ++i) {
                words2MaxCharCount[i] = max(words2MaxCharCount[i], currentWordCount[i]);
            }
        }

        vector<string> answer;

        // compare the char counts for each word in words1 with the max occurance across all words in words2
        for (const string& word : words1) {
            vector<int> currentCharCount(26);
            for (const char& c : word) {
                ++currentCharCount[c-'a'];
            }
            bool failed = false;

            // see if `word` is universal
            for (int i = 0; i < 26; ++i) {
                if (currentCharCount[i] < words2MaxCharCount[i]) {
                    failed = true;
                    break;
                }
            }

            if (!failed) answer.push_back(word);
            
        }
        return answer;
    }
};