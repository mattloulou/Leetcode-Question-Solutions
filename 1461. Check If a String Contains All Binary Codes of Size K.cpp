#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

//V1 integer set solution
class Solution {
public:
    bool hasAllCodes(string s, const int k) {
        unordered_map<char, int> mapping{{'0',0},{'1',1}};
        unordered_set<int> substrings;

        //create a masking for k LSBs.
        int mask = (1 << k) - 1;
        
        int current_value = 0;
        for (int i = 0; i < s.size(); ++i) {
            current_value <<= 1;
            current_value &= mask;
            current_value += mapping.at(s[i]);

            //once we have reached substrings of size k:
            if (i >= k-1) {
                substrings.insert(current_value);
            }
        }

        //check if we have all substrings
        return substrings.size() == pow(2,k);

    }
};

//V2 string set solution (less code than V1, but slower and needs much more memory). Inspired by: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/2092712/C%2B%2B-or-Clean-Code-(4-Lines)-or-Easy-to-understand
class Solution {
public:
    bool hasAllCodes(string s, const int k) {
        unordered_set<string> substrings;

        for (int i = 0; i + (k-1) < s.size(); ++i) {
            substrings.insert(s.substr(i,k));
        }

        //check if we have all substrings
        return substrings.size() == pow(2,k);

    }
};