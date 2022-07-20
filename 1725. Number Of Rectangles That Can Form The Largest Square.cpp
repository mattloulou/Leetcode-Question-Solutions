#include <vector>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxSquareSize = 0;
        int count = 0;
        for (const vector<int>& rectangle : rectangles) {
            const int currentSquare = min(rectangle[0], rectangle[1]);
            if (currentSquare > maxSquareSize) {
                maxSquareSize = currentSquare;
                count = 1;
            } else if (currentSquare == maxSquareSize) {
                ++count;
            }
        }      
        return count;
    }
};