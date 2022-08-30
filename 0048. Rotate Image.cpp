#include <vector>
using namespace std;

// O(n^2) [processes each element only once; the grid is n x n] Solution: rotates each square (when 2 divides n)
// or rectangle (when 2 doesn't divide n) quadrant of the grid.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()/2; ++i) {
            for (int j = 0; j < (matrix.size()+1)/2; ++j) { // this takes into account when the matrix dimensions are even or odd
                rotateFourPixelsClockwise(matrix, j, i);
            }
        }
    }
    
    // takes the top left pixel, and rotates
    void rotateFourPixelsClockwise(vector<vector<int>>& matrix, const int x, const int y) {
        int temp = std::move(matrix[y][x]);
        matrix[y][x] = std::move(matrix[matrix.size()-1-x][y]); // bottom left quadrant to top left
        matrix[matrix.size()-1-x][y] = std::move(matrix[matrix.size()-1-y][matrix.size()-1-x]); // bottom right quadrant to bottom left
        matrix[matrix.size()-1-y][matrix.size()-1-x] = std::move(matrix[x][matrix.size()-1-y]); // top right quadrant to bottom right
        matrix[x][matrix.size()-1-y] = std::move(temp); // top left quadrant to top right
    }
};