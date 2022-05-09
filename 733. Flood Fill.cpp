#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int neighbours[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        int original_colour = image[sr][sc];
        image[sr][sc] = newColor;
        for (const int* movement : neighbours) {
            int new_r = sr + movement[0];
            int new_c = sc + movement[1];
            if (new_r >= 0 && new_r < image.size() && new_c >= 0 && new_c < image.at(0).size() && image[new_r][new_c] == original_colour) {
                floodFill(image, new_r, new_c, newColor);
            }
        }
        return image;
    }
};