#include <string>
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        //first, strip all non-alpha numeric chars. Also, if a char is uppercase, make it lowercase
        string s2 = ""; //don't need [= ""] because the string default constructor is an empty string
        for (int i = 0; i < s.size(); ++i) {

            //tolower() from <cctype> convertes upper-case letters to lower case, 
            //and doesn't change other characters at all.
            if (isalnum(s.at(i))) s2.push_back(tolower(s.at(i))); 
        }

        //next, check for palindrome
        for (int i = 0; i < s2.size()/2; ++i) {
            const int other_index = s2.size()-i-1;
            if (s2.at(i) != s2.at(other_index)) return false;
        }
        return true;
    }
};