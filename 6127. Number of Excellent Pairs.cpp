#include <algorithm>
#include <vector>
using namespace std;

// popcount(a & b) + popcount(a | b) == popcount(a) + popcount(b)
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {

        // first, using our formula, we don't actually care about the numbers in `nums`, just their popcounts.
        // We also don't want duplicates, so we use unique() from <algorithm>
        sort(nums.begin(), nums.end());
        auto end = unique(nums.begin(), nums.end());
        vector<long long> popcounts(32); // this supports popcounts from [0,31]. We can't have 32, as nums is a vector of ints, which would be signed integers.
        for (auto i = nums.begin(); i != end; ++i) {
            ++popcounts[__builtin_popcount(*i)];
        }

        // next, we must find all excellent pairs.
        long long result = 0;
        for (int i = 0; i < popcounts.size(); ++i) {
            if (!popcounts[i]) continue; 
            for (int j = i; j < popcounts.size(); ++j) {

                // we found excellent pairs, as `i` and `j` represent the popcounts. There are different formulas for if i and j are the same. This is because in those cases,
                // we must consider the fact that a number can be a pair with itself only once, but two numbers can make 2 different pairs together (num1,num2) and (num2,num1).
                if (i + j >= k) {
                    if (i == j) {
                        result += popcounts[i] * popcounts[j];
                    } else {
                        result += 2 * popcounts[i] * popcounts[j];
                    }
                    
                }
            }
        }
        return result;
    }
};