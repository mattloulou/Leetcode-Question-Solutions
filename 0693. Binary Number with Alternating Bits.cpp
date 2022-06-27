class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool previous_bit = n & 1;
        n >>= 1;
        while (n) {
            const bool current_bit = n & 1;
            if (!(previous_bit^current_bit)) return false;
            n = ~n;
            n >>= 1;
        }
        return true;
    }
};