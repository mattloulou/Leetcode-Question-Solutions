#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        auto end = unique(nums.begin(), nums.end());
        auto ptr = nums.begin()+1;
        int result = 0;
        
        while (ptr+1 < end) {
            result += ((*(ptr-1) < *ptr) && (*(ptr+1) < *ptr)) || ((*(ptr-1) > *ptr) && (*(ptr+1) > *ptr));
            ++ptr;
        }   
        return result;
    }
};