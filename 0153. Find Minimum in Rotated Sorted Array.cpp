#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size()-1;

        // special case: nums is not rotated
        if (nums[0] < nums[end] || nums.size() == 1) return nums[0];

        while (end >= begin) {
            const int mid = (begin + end) / 2; // we want `mid` to be the largest number, so that the number right of `mid` is the smallest
            if (nums[mid] > nums[(mid+1)%nums.size()]) {
                return nums[(mid+1)%nums.size()];
            } else if (nums[mid] > nums[end]) { // such as for 0<-BEGIN 1 2 3<-MID 4 -2 -1<-END
                begin = mid + 1;
            } else if (nums[mid] < nums[end]) { // such as for 0<-BEGIN 1 2 -4<-MID -3 -2 -1<-END
                end = mid - 1;
            } else {
                // should not happen
            }
        }     
        return 0; // should never be run 
    }
};