// This question turns out to be a duplicate of https://leetcode.com/problems/number-complement/

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0) return 1; // some arbitrary case they gave
        return ((~static_cast<unsigned>(0)) >> __builtin_clz(n)) ^ n;
    }
};

//V2 hargun's solution:
class Solution {
public:
    int bitwiseComplement(int n) {
        int bitLength = 1;
        int k = n;
        while (k >>= 1) {
            (bitLength <<=1 ) += 1;
        }
        return bitLength ^ n;
    }
};