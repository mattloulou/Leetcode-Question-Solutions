#include <string>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        
        //Algorithm:
        //To make a pallindrome, we need some number of pairs of chars, and also optionally 1 of any random char in the middle (odd sized palindrome)
        //So, we will find how many pairs of 2 we can make, and then see if there are any single chars left over.

        //128 indices to easily store all ascii chars (the question just wants upper and lower chars though)
        int letter_counts[128]{0};
        int double_count = 0;

        //we will now find how many pairs of chars can be made.
        for (const char& c : s) {
            (letter_counts[c] += 1) %= 2;
            if (letter_counts[c] == 0) ++double_count;
        }
        
        //now we will see if there is an extra middle characters. 
        //If the current palindrome length is less than the string length, then there is an extra char.
        if (2*double_count < s.size()) {
            return 2*double_count + 1;
        }
        //otherwise, there is not an extra char.
        return 2*double_count;
    }
};