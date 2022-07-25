#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        char ans = '0';
        for (const char& c : n) {
            ans = max(ans, c);
            if (ans == '9') return 9;
        }
        return ans-'0';
    }
};

// Hargun's solution
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};