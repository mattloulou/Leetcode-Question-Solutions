#include <vector>
using namespace std;
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> originalNumber(10);
        digitCount(originalNumber, n);
        int maxPossibleValue = (static_cast<unsigned>(~0) >> 2) + 1;
        for (unsigned int i = maxPossibleValue; i > 0; i >>= 1) {
            vector<int> current(10);
            digitCount(current, i);
            if (vectorsMatch(originalNumber, current)) return true;
        }
        return false;
    }

    void digitCount(vector<int>& v, int n) {
        while (n) {
            ++v[n%10];
            n /= 10;
        }
    }

    bool vectorsMatch(const vector<int>& a, const vector<int>& b) const {
        for (int i = 0; i < 10; ++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

};