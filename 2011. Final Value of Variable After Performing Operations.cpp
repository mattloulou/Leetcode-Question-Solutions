#include <vector>
#include <string>
using namespace std;

//solution improved by https://leetcode.com/problems/final-value-of-variable-after-performing-operations/discuss/1471947/C++-Simple-Solution
//I already had a very similar design but this one is even more concise and cool :D
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (const auto& operation : operations) {
            (operation[1] == '+') ? ++X: --X;
        }
        return X;
    }
};