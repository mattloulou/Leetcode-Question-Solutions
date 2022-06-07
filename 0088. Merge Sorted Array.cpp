#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> combined(m + n);
        int n1 = 0, n2 = 0, combined_index = 0;

        // while the index for both given arrays are within range, keep inserting the smallest
        while (n1 < m && n2 < n) {
            if (nums1[n1] < nums2[n2]) {

                // assign the appropriate value and increment both pointers
                combined[combined_index++] = nums1[n1++];
            } else {
                combined[combined_index++] = nums2[n2++];
            }
        }

        // add in the rest of the numbers
        while (n1 < m) combined[combined_index++] = nums1[n1++];
        while (n2 < n) combined[combined_index++] = nums2[n2++];

        nums1 = combined;
    }
};

// V2 sorting in nums1 from back to front (slightly better memory than V1 since we don't need a new array).
// It is the same as my V1 but it was inspired by https://leetcode.com/problems/merge-sorted-array/discuss/29614/C%2B%2B-solution-runtime-O(n)-in-place-easy-to-understand
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1, n2 = n-1, combined_index = m+n-1;

        // while the index for both given arrays are within range, keep inserting the largest
        while (n1 >= 0 && n2 >= 0) {
            if (nums1[n1] > nums2[n2]) {

                // assign the appropriate value and increment both pointers
                nums1[combined_index--] = nums1[n1--];
            } else {
                nums1[combined_index--] = nums2[n2--];
            }
        }

        // add in the rest of the numbers
        while (n1 >= 0) nums1[combined_index--] = nums1[n1--];
        while (n2 >= 0) nums1[combined_index--] = nums2[n2--];
    }
};
