#include <vector>
using namespace std;
class Solution {
public:
    vector<pair<int,int>> adjacentDirections{{1,0},{0,1},{-1,0},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        // Idea:
        // We begin by searching each row, and recording the connected horizontal pieces of land.
        vector<vector<pair<int,int>>> horizontalIslandPieces(grid.size()); // the pairs store the [start,stop] (inclusive) of land
        
        for (int i = 0; i < grid.size(); ++i) {
            vector<pair<int,int>>& currentRow = horizontalIslandPieces[i];
            bool inIsland = false;

            // loop through the row
            for (int j = 0; j < grid[0].size(); ++j) {

                // if we are on an island
                if (grid[i][j]) {
                    if (!inIsland) {
                        inIsland = true;
                        currentRow.push_back({j,j});
                    } else {
                        ++currentRow.back().second;
                    }
                } else {
                    inIsland = false;
                }
            }
        }

        // now, piece together the islands and find the max size.
        

    }
};