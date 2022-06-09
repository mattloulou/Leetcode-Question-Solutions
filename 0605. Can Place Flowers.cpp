#include <vector>
using namespace std;


//V2 ; works. Could be faster by transfering current -> prev and next -> current.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if (n == 0) return true;

        for (int i = 0; i < flowerbed.size(); ++i) {

            const int prev_pot = (i == 0) ? 0: flowerbed[i-1];
            const int& current_pot = flowerbed[i];
            const int next_pot = (i == flowerbed.size()-1) ? 0: flowerbed[i+1];

            if (!prev_pot && !current_pot && !next_pot) {
                flowerbed[i] = 1;
                if (--n <= 0) return true; // decrement n and check for the primary function condition
            }
        }

        return false;
    }
};

//V3 using counters
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        //edge cases
        if (n == 0) return true;
        if (flowerbed.size() == 1 && flowerbed[0] == 0 && n <= 1) return true;

        //stores the number of zeros in a row.
        int zeros = 1;

        for (int i = 0; i < flowerbed.size(); ++i) {

            if (flowerbed[i] == 1) {
                zeros = 0;
            } else {
                ++zeros;
                if (zeros + static_cast<int>(i == flowerbed.size()-1) >= 3) {
                    flowerbed[i-1] = 1;
                    zeros = 1;
                    if (--n <= 0) return true;
                }
            }
        }
        return false;
    }
};




//V1. Doesn't work! Forgot to consider a case like: [1,0,0,0,0,1], 2.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        bool canPlant = false;

        for (int i = 0; i < flowerbed.size(); ++i) {

            // if the pot is 1, then we reset canPlant (in case it was previously set to true before encountering a 1)
            if (flowerbed[i] == 1) {
                canPlant = false;

            // if the pot is a 0, then we first check if we can plant or not. Then, we toggle canPlant (as you can only plant in alternating empty pots).
            } else {
                if (canPlant) {

                    // decrement n and check for the planting condition
                    if (--n <= 0) return true;
                }

                // flip the value of can plant based on alternating 0s.
                canPlant = !canPlant;
            }
        }

        return false;
    }
};
