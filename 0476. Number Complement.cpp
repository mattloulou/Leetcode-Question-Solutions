class Solution {
public:
    int findComplement(int num) {
        // create a mask with all set bits up until the Most Significant set-bit in num.
        int int_mask = 0;
        while (int_mask < num) {
            int_mask <<= 1;
            int_mask += 1;
        }
        return num ^= int_mask;
    }
};

//V2 (learned from here: https://leetcode.com/problems/number-complement/discuss/96017/3-line-1-line-C%2B%2B)
class Solution {
public:
    int findComplement(int num) {
        const int num_leading_zeroes = __builtin_clz(num);
        return ((~static_cast<unsigned>(0)) >> num_leading_zeroes) ^ num;
    }
};