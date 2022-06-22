// I can use this solution because k can be at most 10 (since num is at most 1 billion).
class Solution {
public:
    int divisorSubstrings(int num, int k) {

        // power_of_ten = 10^k
        long power_of_ten = 1;
        for (int i = 0; i < k; ++i) {
            power_of_ten *= 10;
        }

        // we now make a copy of num, and go through obtaining each substring with k digits.
        int num_copy = num;
        int result = 0;
        while (num_copy >= (power_of_ten/10)) { // we must keep going while there are at least k digits left in num_copy.
            
            // obtain the substring
            const int substring = num_copy % power_of_ten;
            
            // 0 is not a divisor of anything
            if (substring != 0) {
                result += (num % substring == 0);
            }

            // shift it right one digit.
            num_copy /= 10; 
        }
        return result;
    }
};