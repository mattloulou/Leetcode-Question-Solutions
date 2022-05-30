#include <iostream>
using namespace std;
//V1 recursive version. It is correct but gives TLE :(  
class Solution {
public:

    //if you have n steps remaining, you can either make a double-step or single-step right now. Sum their possible solutions together.
    int climbStairs(int n) {
        if (n <= 1) return 1;
        else {
            return climbStairs(n-1) + climbStairs(n-2);
        }
    }
};

//wow, it is the fibonacci pattern.
int main() {
    Solution s;
    for (int i = 0; i < 10; ++i) {
        cout << s.climbStairs(i) << endl;
    }
}

//V2 Fibonacci solution. Main solution
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int first = 1;
        int second = 2;
        for (int i = 2; i < n; ++i) {
            const int temp = second;
            second = first + second;
            first = temp;
        }
        return second;
    }
};

//V3 minimalist solution from: https://leetcode.com/problems/climbing-stairs/discuss/25296/3-4-short-lines-in-every-language
int climbStairs(int n) {
    int first = 1, second = 1;     // 0 1 1 ... ... ... first second ... ...
    while (--n)
        first = (second += first) - first;
    return second;
}