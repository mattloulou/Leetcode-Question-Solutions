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