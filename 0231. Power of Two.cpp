//V1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // the question says only positive numbers can be powers of two.
        return !(n&(n-1)); // return (n&(n-1)) == 0;
    }
};


//V2 (optimization is inspired by: https://leetcode.com/problems/power-of-two/discuss/1638707/PythonC%2B%2BJava-Detailly-Explain-Why-n-and-n-1-Works-oror-1-Line-oror-100-Faster-oror-Easy)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1)); // return (n&(n-1)) == 0;
    }
};