#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> counts; // {sum of digits, max value for that sum of digits}
        int maxReturn = -1;
        for (const int& num : nums) {
            const int digitCount = sumDigits(num);
            if (!counts.count(digitCount)) {
                counts.insert({digitCount, num});
            } else {

                // check if the return value is the largest foun so far
                maxReturn = max(maxReturn, counts[digitCount] + num);

                //update the value in the map
                counts[digitCount] = max(counts[digitCount], num);
            }
        }
        return maxReturn;
    }

    int sumDigits(int num) {
        int ret = 0;
        while (num > 0) {
            ret += num%10;
            num /= 10;
        }
        return ret;
    }
};