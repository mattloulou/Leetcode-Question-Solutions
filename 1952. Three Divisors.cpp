#include <cmath>
class Solution {
public:
    bool isThree(int n) {
        // 1 and n are guaranteed to be 2 divisors (unless n == 1)
        if (n == 1) return false;


        // To have exactly 3 divisors, something must only have sqrt(n) as the other divisor.
        
        int sroot = static_cast<int>(sqrt(n));
        if (sroot*sroot != n) return false; // if sqrt(n) is not an integer, it can't have exactly 3 divisors

        // if we find some other divisor, it will have more than 3 divisors.
        for (int i = 2; i < sroot; ++i) {
            if (n%i == 0) return false;
        }

        return true;
    }
};

class Solution {
public:
    bool isThree(int n) {
        if (n <= 3) return false;

        bool foundThirdDivisor = false;
        for (int i = 2; i*i <= n; ++i) {
            if (n%i == 0) {
                foundThirdDivisor = true;
                if (i*i != n) return false;
            }
        }

        return foundThirdDivisor;
    }
};