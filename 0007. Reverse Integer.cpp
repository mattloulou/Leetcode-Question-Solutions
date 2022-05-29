using namespace std;
class Solution {
public:
    int reverse(int x) {

        //capture if x is negative or not to reapply to the final result
        bool negative = false;
        if (x < 0) {
            negative = true;
        }

        //store the flipped int in a long (to prevent overflow). This will work if x is negative or positive
        long result = 0;
        while (x != 0) {
            int digit = abs(x % 10);
            x/=10;
            result *= 10; //MISTAKE: I originally put this statement after `result += digit;` instead of before like it is here
            result += digit;
            
        }

        if (negative) result *= -1;

        //we will just cast it to an int if
        return (result > INT_MAX || result < INT_MIN) ? 0: static_cast<int>(result); 
    }
};