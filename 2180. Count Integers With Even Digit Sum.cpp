// Tried to use a fancy algorithm but it didn't work
class Solution {
public:
    int countEven(int num) {
        int result = num/20 * 10;  // <-- this is because there is a cycle which repeats every 20 digits, which contains 10 numbers.
        
        // manually go through the remaining numbers
        const int remainder = num%20;
        if (remainder <= 9) return remainder/2 + result;
        return (remainder-1)/2 + result;
    }
};

// just brute force (actually works)
class Solution {
public:
    int countEven(int num) {
        int result = 0;
        for (int i = 1; i <= num; ++i) {
            result += digitCountEven(i);
        }
        return result;
    }

    bool digitCountEven(int num) {
        int digitSum = 0;
        while (num) {
            digitSum += num%10;
            num/=10;
        }
        return !(digitSum%2);
    }
};