#include <vector>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int result = 0;

        for (int i = 0; i < grid.size(); ++i) {
            vector<int>& row = grid[i];
            for (int col = 0; col < grid.size(); ++col) {

                // here, `result` will increase by the number of squares that match. But, if the row&col don't match,
                // I undo it. So, at the end, we just return result/grid.size()
                for (int square = 0; square < grid.size(); ++square, ++result) {
                    if (row[square] != grid[square][col]) {
                        result -= square;
                        break;
                    } 
                }
            }
        }
        return result/grid.size();
    }
};