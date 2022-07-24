#include <unordered_set>
using namespace std;
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> found;
        for (const char& c : s) {
            if (found.count(c)) return c;
            found.insert(c);
        }      
        return 0; // never should be called
    }
};