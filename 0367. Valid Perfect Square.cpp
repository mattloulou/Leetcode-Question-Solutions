// V1
using ull = unsigned long long;
class Solution {
public:
    bool isPerfectSquare(int num) {
        ull i = 1;
        while (true) {
            const ull product = i*i;
            if (num == product) return true;
            if (num < product) return false;
            ++i;
        }
    }
};

// V2: basically do binary search for the number.
class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long lower = 1, upper = num;
        while (lower <= upper) {
            unsigned long mid = (lower + upper)/2;
            if (num%mid == 0 && mid == num/mid) { // the first condition is required to combat integer division in num/mid
                return true;
            }
            if (mid < num/mid) {
                lower = mid+1;
            } else {
                upper = mid-1;
            }
        }
        return false;
    }
};