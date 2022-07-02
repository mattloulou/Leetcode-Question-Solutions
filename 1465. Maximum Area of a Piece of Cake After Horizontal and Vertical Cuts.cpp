#include <vector>
#include <algorithm>
using namespace std;

// V1: you can see with some thinking that you actually just need to find the larges gaps in the
// horizontal and vertical slices, and multiply them together. To see why, let us begin by first imagining there are
// only horizontal slices. Then, as this is a rectangular cake, there will be one section with the largest (or tied)
// area. Then, when you introduce vertical slices, they will chop up each horizontal section into the same ratios.
// Thus, the final maximum section will be bordered by the horizontal cuts making the largest horizontal section,
// along with the vertical cuts which divide that into the largest section of itself.
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxH = horizontalCuts[0]; // start with the first distance (0 to horizontalCuts[0])
        int maxV = verticalCuts[0]; // start with the first distance (0 to verticalCuts[0])
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            maxH = max(maxH, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            maxV = max(maxV, verticalCuts[i]-verticalCuts[i-1]);
        }

        //consider the final values
        maxH = max(maxH, h - horizontalCuts.back());
        maxV = max(maxV, w - verticalCuts.back());
        return static_cast<int>((static_cast<long>(maxH)*maxV) % 1000000007);
    }
};