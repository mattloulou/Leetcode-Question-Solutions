#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size()-2, vector<int>(grid.size()-2));
        for (int i = 1; i < grid.size()-1; ++i) { // MISTAKE: originally I did `grid.size()-2` instead of `grid.size()-1` :(
            for (int j = 1; j < grid.size()-1; ++j) { // MISTAKE: originally I did `grid.size()-2` instead of `grid.size()-1` :(
                ans[i-1][j-1] = getLocalMax(grid, i, j);
            }
        }
        return ans;
    }

    int getLocalMax(const vector<vector<int>>& grid, const int i, const int j) {

        int localMax = 0; // question says grid[x][y] >= 1
        for (int y = i-1; y <= i+1; ++y) {
            for (int x = j-1; x <= j+1; ++x) {
                localMax = max(localMax, grid[y][x]);
            }
        }
        return localMax;
    }
};