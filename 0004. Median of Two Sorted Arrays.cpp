//UNFINISHED!!!!!!!!!!!!!!!!!!!!!!!!

#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int size1 = nums1.size();
        const int size2 = nums2.size();
        int start1 = 0;
        int end1 = size1 - 1;
        int current2 = size2/2;

        //basically we will keep doing binary search on the first arrayand adjust the second array by the change in position until we find the median.
        while (start1 < end1) {

        }
    }
};