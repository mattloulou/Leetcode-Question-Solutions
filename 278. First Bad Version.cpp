// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
using ul = unsigned long;
class Solution {
public:
    int firstBadVersion(int n) {
        ul start = 1;
        ul end = n;
        ul mid = (start + end)/2;

        //we keep using binary search until start == end, which will be when both are on the very first bad version.
        while (start < end) {
            if (!isBadVersion(mid)) { //this is a magical function given by leetcode

                //if mid is not bad, then the first bad version will be after mid.
                start = mid + 1;
                
            } else {

                //the reason there is no -1 is because if mid is the first bad version, we don't want end to go before it.
                //In that case, the algorithm will still work. This is because as long as the range is > 1, mid will never be the same as end 
                //(due to interger addition), which means start will keep getting larger until it reaches end.

                //if mid is bad, then the first bad version will be <= mid, so end gets moved to exactly mid.
                end = mid; 
            }
            mid = (start + end)/2;
        }
        return start; //now they should be equal to each other
    }

    //this is a magical function given by leetcode
    //COMMENT OUT FOR SUBMISSION
    bool isBadVersion(int guess);
};