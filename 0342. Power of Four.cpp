#include <cstdint>
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        uint32_t num = static_cast<unsigned>(n);

        // if there are an odd number of leading 0s (as will be the case for powers of 4 in 32bits) && there is only 1 set bit
        return (__builtin_clz(num) & 1) && ((num & (num-1)) == 0);
    }
};


// V2 another good solution (https://leetcode.com/problems/power-of-four/discuss/80460/1-line-C%2B%2B-solution-without-confusing-bit-manipulations)
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};