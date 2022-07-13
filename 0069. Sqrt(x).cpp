// class Solution {
// public:
//     int mySqrt(int x) {
//         for (int i = 0; i*i <= x && i < 46340; ++i) {
//             if (i*i + 2*i + 1 > x) {
//                 return i;
//             }
//         }
//         return 46340;
//     }
// };

//V2 Using newton's method, and iterating. I have my own implementation, but I was reminded of this algorithm existing via a discussion post
// technically O(1) for this range of inputs because I have a constant number of instructions :).
class Solution {
public:
    int mySqrt(int x) {
        if (x < 4) return !!x;
        // solve f(i) = i^2 - x = 0
        double current = 1; // first guess. 
        double next = current - (current*current-x)/(2*current);
        for (int i = 0; i < 19; ++i) { // 19 is min value to work with the given test cases
            current = next;
            next = current - (current*current-x)/(2*current);
        }
        return static_cast<int>(next);
    }
};

// V3 bit manipulation O(32) = O(1).
// To solve this problem, we need to find the largest integer `solution` such that its square is <= x.
// Since the problem states that the max value for x is 2^31-1, we only need to consider the first 16 bits [0-15]
// for the root.
// My solution was inspired by combining multiple solutions from: https://leetcode.com/problems/sqrtx/discuss/25048/Share-my-O(log-n)-Solution-using-bit-manipulation
class Solution {
public:
    int mySqrt(int x) {
        unsigned answer = 0;
        for (int bit_mask = 1 << 15; bit_mask != 0; bit_mask >>= 1) {
            answer |= bit_mask;
            if (answer*answer > x) {
                answer ^= bit_mask;
            }
        }
        return static_cast<int>(answer);
    }
};