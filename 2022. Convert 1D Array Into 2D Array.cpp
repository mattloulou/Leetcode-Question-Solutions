#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m*n) return vector<vector<int>>{};

        vector<vector<int>> solution(m, vector<int>(n));
        for (int mIndex = 0; mIndex < m; ++mIndex) {
            for (int nIndex = 0; nIndex < n; ++nIndex) {
                solution[mIndex][nIndex] = std::move(original[mIndex*n + nIndex]);
            }
        }      
        return solution;
    }
};