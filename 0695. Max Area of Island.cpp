#include <vector>
using namespace std;

// V(mn) There is no need for a visited array, as the grid can act as that.
class Solution {
public:
    vector<pair<int,int>> adjacentDirections{{1,0},{0,1},{-1,0},{0,-1}};    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col]) {
                    grid[row][col] = 0;
                    maxArea = max(maxArea, DFS(grid, row, col));
                }
            }
        }
        return maxArea;

    }

    int DFS(vector<vector<int>>& grid, int row, int col) {
        int neighbourSum = 1;
        for (const pair<int,int>& direction : adjacentDirections) {
            const int newRow = row + direction.first;
            const int newCol = col + direction.second;
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() 
                && grid[newRow][newCol]) {
                grid[newRow][newCol] = 0;
                neighbourSum += DFS(grid, newRow, newCol);
            }
        }
        return neighbourSum;
    }
};

// Failed alternate solution attempt
// class Solution {
// public:
//     vector<pair<int,int>> adjacentDirections{{1,0},{0,1},{-1,0},{0,-1}};
//     int maxAreaOfIsland(vector<vector<int>>& grid) {

//         // Idea:
//         // We begin by searching each row, and recording the connected horizontal pieces of land.
//         vector<vector<pair<int,int>>> horizontalIslandPieces(grid.size()); // the pairs store the [start,stop] (inclusive) of land
        
//         for (int i = 0; i < grid.size(); ++i) {
//             vector<pair<int,int>>& currentRow = horizontalIslandPieces[i];
//             bool inIsland = false;

//             // loop through the row
//             for (int j = 0; j < grid[0].size(); ++j) {

//                 // if we are on an island
//                 if (grid[i][j]) {
//                     if (!inIsland) {
//                         inIsland = true;
//                         currentRow.push_back({j,j});
//                     } else {
//                         ++currentRow.back().second;
//                     }
//                 } else {
//                     inIsland = false;
//                 }
//             }
//         }

//         // now, piece together the islands and find the max size.
        

//     }
// };