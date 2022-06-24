class Solution {
public:
    int findComplement(int num) {
        // create a mask with all set bits up until the Most Significant set-bit in num.
        int int_mask = 0;
        while (int_mask < num) {
            int_mask <<= 1;
            int_mask += 1;
        }
        return num ^= int_mask;
    }
};