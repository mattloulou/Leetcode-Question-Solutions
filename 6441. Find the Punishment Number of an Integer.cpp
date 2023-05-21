#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

// this solution is only correct if the number `i` can be constructed from at most 2 substrings.
// If it requires >2, then this does not work, such as the case where `i=36`., where 36*36 = 1296 --> 1 + 29 + 6 = 36
class Solution {
public:
    int punishmentNumber(int n) {
        long result = 0;
        for (int i = 1; i <= n; ++i) {
            string s = std::to_string(i*i);
            for (int j = 0; j < s.length(); ++j) {
                long first = (s.substr(0, j).empty()) ? 0: stoi(s.substr(0, j));
                long second = (s.substr(j).empty()) ? 0: stoi(s.substr(j));
                if (first + second == i) {
                    result += i*i;
                }
            }
        }
        return result;
    }
};