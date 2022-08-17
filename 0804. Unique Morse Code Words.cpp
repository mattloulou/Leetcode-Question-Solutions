#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> morseCodeTransformations;
        vector<string> charToMorseCode{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (const auto& w : words) {
            string transformation;
            for (const auto& c : w) {
                transformation += charToMorseCode[c-'a'];
            }
            morseCodeTransformations.insert(transformation);
        }
        return morseCodeTransformations.size();
    }
};