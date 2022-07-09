#include <vector>
#include <unordered_set>
using namespace std;

// O(mn) time, O(m+n) space.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // first, figure out which columns and rows must be modified.
        unordered_set<int> cols, rows;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == 0) {
                    rows.insert(row);
                    cols.insert(col);
                }
            }
        }     

        // next, set appropriate cells to 0;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (rows.count(row) || cols.count(col)) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};

//V2 O(mn) time, O(1) extra space. Based off of: https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution/223761
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int rowSize = matrix.size(), colSize = matrix[0].size();

        // first, we collect data on the first row and column, to see if they are to be reset or not:

        bool firstRowZero = false, firstColZero = false;

        // first row:
        for (int col = 0; col < colSize; ++col) {
            if (matrix[0][col] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // first col:
        for (int row = 0; row < rowSize; ++row) {
            if (matrix[row][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        

        // now, we go through the rest of the matrix (except the first row and column). If we come across an entry that is 0, we know the row and column will become 0. 
        // So, we can use the first row and column to store the fact that the row and column must be set to 0 later. We do not lose any data, since they must become 0 anyway.
        // The reason why we had to do something special for the first column and row is because we needed to scan through them first and determine if they
        // must be set to 0, so that we could use them for storage now.
        for (int row = 1; row < rowSize; ++row) {
            for (int col = 1; col < colSize; ++col) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }


        // now, process the data for the part of the matrix which excludes the first row && col:

        // first row:
        for (int col = 1; col < colSize; ++col) {
            if (matrix[0][col] == 0) {
                for (int row = 1; row < rowSize; ++row) {
                    matrix[row][col] = 0;
                }
            }
        }

        // first col:
        for (int row = 1; row < rowSize; ++row) {
            if (matrix[row][0] == 0) {
                for (int col = 1; col < colSize; ++col) {
                    matrix[row][col] = 0;
                }
            }
        }


        // now, process the data for just the first row && col:
        if (firstRowZero) {
            for (int col = 0; col < colSize; ++col) {
                matrix[0][col] = 0;
            }
        }
        if (firstColZero) {
            for (int row = 0; row < rowSize; ++row) {
                matrix[row][0] = 0;
            }
        }
    }
};
