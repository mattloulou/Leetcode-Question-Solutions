#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> m;
        char currentChar = 'a';
        
        for (const auto& c : key) {
            if (c != ' ' && !m.count(c)) { // MISTAKE: I forgot to consider spaces originally (for when c == ' ')
                m.insert({c,currentChar});
                ++currentChar;
                if (m.size() == 26) break;
            }
        }

        string decoded;

        for (const auto& c : message) {
            if (c != ' ') {
                decoded.push_back(m[c]);
            } else {
                decoded.push_back(' ');
            }
        }

        return decoded;
    }
};