#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

// This solution TLEs :(. It is the brute force method
class Solution {
public:
    int countSpecialNumbers(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += digitsUnique(i); // MISTAKE: originally did digitsUnique(n) instead of digitsUnique(i) :(
        }
        return result;
    }

    bool digitsUnique(int n) {
        int digitsRemaining = 1023; // 1111111111 from binary into hex
        int currentDigit;
        while (n) {
            currentDigit = n%10;
            n /= 10;

            // if the bit is still a 1, then the digit was not used yet.
            if (digitsRemaining & (1 << currentDigit)) {
                digitsRemaining ^= (1 << currentDigit); // flip the bit (set it to 0)

            // if the bit is not a 1, then it was already used
            } else {
                return false;
            }
        }
        return true;
    }
};