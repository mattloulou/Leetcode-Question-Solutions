#include <string>
using namespace std;
class Solution {
public:
    bool checkString(string s) {
        return s.find_last_of('a') <= s.find_first_of('b') || s.find_last_of('a') == string::npos; // this covers all cases: when there is just 'a's, just a 'b's, both, or neither.
    }
};