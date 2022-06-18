#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        // simply change the 6 in the most significant digit to a 9.
        int num_copy = num;
        int highest_digit = -1;
        int digit = 0;

        //find the largest 6
        while (num_copy > 0) {
            if (num_copy%10 == 6) {
                highest_digit = digit;
            }
            num_copy /= 10;
            ++digit;
        }
    
        // increment num to turn the 6 into a 9.
        int addition = 3;
        for (int i = 1; i <= highest_digit; ++i) addition*=10;
        addition = (highest_digit >= 0) ? addition: 0; // if highest_digit == -1, then there were no 6s (num is made from only 9s).
        return num + addition;
    }
};


// V2; easier
class Solution {
public:
    int maximum69Number (int num) {
        // simply change the 6 in the most significant digit to a 9.
        string number = to_string(num);
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] == '6') {
                number[i] = '9';
                return stoi(number);
            }
        }
        return num;
    }
};