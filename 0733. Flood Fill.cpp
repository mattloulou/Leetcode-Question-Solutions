#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int neighbours[4][2] = {{1,0},{0,1},{0,-1},{-1,0}}; //a list of 2D directions to neighbouring squares
        int original_colour = image[sr][sc];
        image[sr][sc] = newColor;

        //this line caused me a headache for a couple minutes... I kept getting stack overflow issues which would make a lot of sense without this line as it covers
        //cases where the newColor is the same as the colour of the pixel it is being applied to, and with at least one neighbour of the same colour.
        if (newColor == original_colour) return image; 
        
        //check out each adjacent square
        for (const int* movement : neighbours) {
            const int new_r = sr + movement[0];
            const int new_c = sc + movement[1];

            //if the new coordinate is within the bounds of 'image', and matches the original colour being filled, do a recursive call
            if (new_r >= 0 && new_r < image.size() && new_c >= 0 && new_c < image.at(0).size() && image[new_r][new_c] == original_colour) {
                floodFill(image, new_r, new_c, newColor);
            }
        }
        return image;
    }
};