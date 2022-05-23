#include <vector>
using namespace std;

//V1 presumably slower approach using vectors:
/*class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) return false;

        vector<int> num;
        int digit;

        //load x into a vector
        while (x > 0) {
            digit = x % 10;
            x /= 10;
            num.emplace_back(digit);
        }

        //check for palindrome
        for (int i = 0; i < num.size()/2; ++i) {
            if (num[i] != num[num.size()-i-1]) return false;
        }
        return true;
    }
};*/

//V2 probably faster approach. Method: flipping the number then comparing
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int x_copy = x;
        unsigned int reverse_x = 0;
        while (x_copy > 0) {
            reverse_x = reverse_x*10 + x_copy%10;
            x_copy /= 10;
        }
        return reverse_x == x;
    }
};
