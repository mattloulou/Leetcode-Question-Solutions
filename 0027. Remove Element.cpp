#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        
        auto beginning = nums.begin();
        auto end = nums.end()-1;

        while (beginning < end) {
            if (*beginning == val) {
                *beginning = std::move(*end);
                --end;
                // we don't do ++beginning here in case the value moved to *beginning == val
            } else {
                ++beginning;
            }
        }      

        // now they are both at the same index
        if (*beginning == val) {
            return beginning - nums.begin();
        } else {
            return beginning - nums.begin() + 1; 
        }
    }
};