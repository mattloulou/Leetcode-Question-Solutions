#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for (int i = 1; i <= n; ++i) {
            const bool multipleOf3 = (i % 3 == 0);
            const bool multipleOf5 = (i % 5 == 0);
            if (multipleOf3 && multipleOf5) {
                ans[i-1] = "FizzBuzz";
            }   
            else if (multipleOf3) {
                ans[i-1] = "Fizz";
            }
            else if (multipleOf5) {
                ans[i-1] = "Buzz";
            }
            else {
                ans[i-1] = to_string(i);
            }
        }      
        return ans;
    }
};