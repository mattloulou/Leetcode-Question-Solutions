#include <string>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size()-1; i >= 0; --i) {
            if ((num[i]%2) != 0) { // note that odd numbers have odd ASCII values
                return num.substr(0,i+1);
            }
        }     
        return ""; 
    }
};