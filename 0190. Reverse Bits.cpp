#include <cstdint> 
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t new_num = 0;
        for (int i = 0; i < 32; ++i) {
            new_num <<= 1;
            new_num += n&1;
            n >>= 1;
        }
        return new_num;
    }
};

//V2 Cool solution (https://leetcode.com/problems/reverse-bits/discuss/54741/O(1)-bit-operation-C%2B%2B-solution-(8ms))