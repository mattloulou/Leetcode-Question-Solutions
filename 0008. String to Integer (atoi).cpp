#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int charIndex = 0;

        // 1. ignore whitespace
        while (charIndex < s.size() && s[charIndex] == ' ') {
            ++charIndex;
        }

        if (charIndex >= s.size()) return 0;

        // 2. read in +/-
        bool sign; // + is true, - is false.
        if (s[charIndex] == '-') {
            sign = false;
            ++charIndex;
        } else if (s[charIndex] == '+') {
            sign = true;
            ++charIndex;
        } else {
            sign = true;
        }

        if (charIndex >= s.size()) return 0;

        // 3. read in until non-digit char
        long result = 0;
        const long max = 2147483647;
        const long min = 2147483648;
        while (charIndex < s.size() && isdigit(s[charIndex])) {
            result *= 10;
            result += s[charIndex++]-'0';

            if (sign && result >= max) {
                return INT_MAX;
            } else if (!sign && result >= min) {
                return INT_MIN;
            }
        }

        if (sign) {
            return static_cast<int>(result);
        } else {
            return -static_cast<int>(result);
        }
    }
};