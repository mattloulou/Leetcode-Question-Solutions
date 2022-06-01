#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string addBinary(string& a, string& b) {
        bool hasCarry = false;
        string result = "";
        int aindex = a.size()-1;
        int bindex = b.size()-1;

        //do the math for each shared digit now
        while (aindex >= 0 || bindex >= 0 || hasCarry) {

            //find the char for the current index for a and b, and also decrement their indices (only when they are non-negative though; helps with efficiency!).
            const char achar = (aindex >= 0) ? a[aindex--]: '0';
            const char bchar = (bindex >= 0) ? b[bindex--]: '0';

            //find the total sum for this index in the result.
            const int sum = hasCarry + (achar-'0') + (bchar-'0'); 

            //update the carry for the next position
            hasCarry = sum >= 2;

            //add this new value onto the result string.
            const char new_value = '0' + (sum - hasCarry*2);
            result = new_value + result;
        }

        return result;
    }
};