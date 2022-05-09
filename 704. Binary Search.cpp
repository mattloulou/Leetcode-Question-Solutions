#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() -1;
        while (start <= end) {
            int middle = (start + end)/2;
            if (nums.at(middle) < target) {
                start = middle + 1;
            } else if (nums.at(middle) > target) {
                end = middle - 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};