#include <vector>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int answer = 0;
        while (x > 0 || y > 0) {
            answer += ((x&1) != (y&1)); // check if the first bits differ
            x >>= 1;
            y >>= 1;
        }
        return answer;
    }
};

//V2 (more efficient) using an alternate method: https://leetcode.com/problems/hamming-distance/discuss/94705/My-C%2B%2B-solution-using-bit-manipulation
class Solution {
public:
    int hammingDistance(int x, int y) {
        int answer = 0, n = x ^ y; // n will have a set-bit wherever x and y differ.
        while (n) {
            ++answer;
            n &= n-1; // pop the Least Significant Set-bit.
        }
        return answer;
    }
};
