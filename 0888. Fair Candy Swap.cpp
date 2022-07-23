#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;
        unordered_set<int> alice;
        for (const int& i : aliceSizes) {
            sumA += i;
            alice.insert(i);
        }
        sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        const int difference = sumA - sumB;

        for (const int& i : bobSizes) {
            const int differenceAfterBobGives = difference + (2*i);
            if (differenceAfterBobGives % 2 == 0 && alice.count(differenceAfterBobGives/2)) {
                return {differenceAfterBobGives/2, i};
            }
        }

        return {-1,-1};
    }
};  