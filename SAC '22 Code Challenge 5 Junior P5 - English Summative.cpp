#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//this returns the number of times a char in a word is the same as the following one.
int SelfContainedDoubleCharCount(const string& word) {
    int count = 0;
    for (int i = 0; i < int(word.size()-1); ++i) {
        if (word.at(i) == word.at(i+1)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int score = 0;
    int N;
    cin >> N;

    //the first word is always counted since it can never be more optimal to remove it
    string word;
    vector<char> ending_chars;
    cin >> word;
    ending_chars.push_back(word.at(word.size()-1));
    score += SelfContainedDoubleCharCount(word);

    //now, we will keep going through the remaining 'words' an see if they are worth includin or not.
    for (int i = 1; i < N; ++i) {

        //get the word
        cin >> word;
        int current_word_score = SelfContainedDoubleCharCount(word);

        //keep the word since removing it can't be better. This is because if you remove it, the best that can happen
        //is that the end of the last word, and the start of some future word are the same (giving +1 points).
        //So, if this makes you at least one point, you may as well keep it (since it can get you more from double-chars between words).
        if (current_word_score > 0) {
            score += current_word_score;

            //extra point if the end of the last word included, and the start of this word, have the same char.
            score += (find(ending_chars.begin(), ending_chars.end(), word.at(0)) != ending_chars.end()) ? 1: 0;
            ending_chars.clear();
            ending_chars.push_back(word.at(word.size()-1));

        //case where the start of this word and the end of the last word match. We will then include this word to claim the points immediately.
        } else if (find(ending_chars.begin(), ending_chars.end(), word.at(0)) != ending_chars.end()) { //current_word_score == 0 in this case
            score += 1;
            ending_chars.clear();
            ending_chars.push_back(word.at(word.size()-1));
        
        //this word provides no points and does not match with the last word. The only way it can get points is if it can make a point by matching 
        //with the start of some future word. We will then "optionally keep the word" by storing its ending char like the one from previous words 
        //as it is possible to still be matched.
        } else {
            ending_chars.push_back(word.at(word.size()-1));
        }
    } 
    cout << score << endl;
}

