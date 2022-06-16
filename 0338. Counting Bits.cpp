#include <vector>
using namespace std;

// V1 O(nlogn) ?
class Solution {
public:
    // main function of the program
    vector<int> countBits(int n) {
        vector<int> answer(n+1,0);        
        for (int i = 0; i <= n; ++i) {
            answer[i] = countOnes(i);
        }
        return answer;
    }

    // returns the number of 1 bits inside the binary representation of a number
    int countOnes(int n) {
        int result = 0;
        while (n > 0) {
            result += n&1;
            n >>= 1;
        }
        return result;
    }
};

// V2 O(n)
class Solution {
public:
    // main function of the program
    vector<int> countBits(int n) {
        vector<int> answer(n+1,0);
        for (int i = 0; i <= n; ++i) {

            // if the number is even, then it is just <<= 1 of the number half of it,, which would have the same count.
            if (i%2 == 0) {
                answer[i] = answer[i/2];

            // if `i` is odd, then it has the same number of bits of `i/2` (with integer division), then plus one.
            // That "plus one" will always be on a bit that is 0 (after the bitshift left), which will then always guarantee an extra bit.
            // note: to make an odd number, you start with an even, multiply by 2 (bitshift 1 left), then add 1 (guaranteed to add a bit).
            } else {
                answer[i] = answer[i/2] + 1;
            }
        }
        return answer;
    }
};

// V3: O(n) same solution as V2 but with more concise code
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n+1,0);
        for (int i = 0; i <= n; ++i) {
            answer[i] = answer[i/2] + (i&1); // i&1 checks if it is odd
        }
        return answer;
    }
};

// V4: O(n) But with a different method source: https://leetcode.com/problems/counting-bits/discuss/79527/Four-lines-C%2B%2B-time-O(n)-space-O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n+1,0);
        for (int i = 1; i <= n; ++i) { //Mistake: at first I started with `i=0`, but it should be `i=1`.
            // the logic here is that i&(i-1) drops the lowest bit of `i`. We then know that `i&(i-1)` has one less bit that `i`, so we just add it
            answer[i] = answer[i&(i-1)] + 1;
        }
        return answer;
    }
};