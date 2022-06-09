#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> solution{{1}};
        for (int i = 2; i <= numRows; ++i) {
            
            // create a new vector/row with size `i` with all values preset to 1
            solution.push_back(vector<int>(i, 1)); 
            
            // calculate the values in the middle of each row
            for (int j = 1; j < i-1; ++j) {
                solution.back()[j] = solution[i-2][j-1] + solution[i-2][j];
            }
        }

        return solution;
    }
};