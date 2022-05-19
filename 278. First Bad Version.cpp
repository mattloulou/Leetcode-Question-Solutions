// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
using ul = unsigned long;
class Solution {
public:
    int firstBadVersion(int n) {
        ul start = 1;
        ul end = n;
        ul guess = (start + end)/2;

        while (start < end) {
            if (!isBadVersion(guess)) { //this is a magical function given by leetcode
                start = guess + 1;
            } else {
                end = guess;
            }
            guess = (start + end)/2;
        }
        return start; //now they should be equal to each other
    }

    //this is a magical function given by leetcode
    //COMMENT OUT FOR SUBMISSION
    bool isBadVersion(int guess);
};