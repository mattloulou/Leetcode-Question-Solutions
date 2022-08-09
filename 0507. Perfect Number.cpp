//V1 simple but less-efficient version
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int sumOfDivisors = 1;
        int i = 2;
        for (int i = 2; i*i <= num; ++i) {
            if (num % i == 0) {
                sumOfDivisors += i;
                if (num/i != i) sumOfDivisors += num/i;
            }
        }
        return sumOfDivisors == num;
    }
};

//V2 more efficient
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int sumOfDivisors = 1;
        int i = 2;
        for (; i*i < num; ++i) {
            if (num % i == 0) {
                sumOfDivisors += i;
                sumOfDivisors += num/i;
            }
        }
        if (i*i == num) sumOfDivisors += i;
        return sumOfDivisors == num;
    }
};