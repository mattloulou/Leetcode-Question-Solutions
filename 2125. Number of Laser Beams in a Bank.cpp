#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0;
        int prev_count = 0;
        for (int i = 0; i < bank.size(); ++i) {
            const int current_popcount = popcount(bank[i]);
            if (current_popcount) {
                result += prev_count * current_popcount;
                prev_count = current_popcount;
            }
        }
        return result;
    }

    int popcount(const string& s) {
        int result = 0;
        for (const char& c : s) {
            result += c - '0';
        }
        return result;
    }
};