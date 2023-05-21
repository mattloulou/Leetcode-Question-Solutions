#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        while (s.find("AB") != string::npos || s.find("CD") != string::npos) {
            while (s.find("AB") != string::npos) {
                s.erase(s.find("AB"), 2);
            }
            
            while (s.find("CD") != string::npos) {
                s.erase(s.find("CD"), 2);
            }
        }
        
        return s.length();
    }
};