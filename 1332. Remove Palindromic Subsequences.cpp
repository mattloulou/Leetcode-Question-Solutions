#include <string>
using namespace std;

//Solution 1: https://leetcode.com/problems/remove-palindromic-subsequences/discuss/1099494/JS-Python-Java-C%2B%2B-or-Easy-Solution-w-Explanation
// The solution must be <= 2. If the string is empty, it is 0. If it is a pallindrome, it is 1. If it is anything else, it is 2.
// It is 2 because since we only need palindromic subsequences, you can always take all 'a's as your first palindromic subsequence, and all 'b's as the other.
class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0; // s is ""
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-i-1]) return 2; // `s` is not a palindrome
        }
        return 1; // s is a palindrome
    }
};
