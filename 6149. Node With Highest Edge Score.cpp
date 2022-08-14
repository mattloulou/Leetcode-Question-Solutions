#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int maxVertex = -1;
        unsigned long long maxEdgeCount = 0;
        unordered_map<int, unsigned long long> m;

        for (int i = 0; i < edges.size(); ++i) {
            const int& edgeDestiation = edges[i];
            m[edgeDestiation] += i;
            if (m[edgeDestiation] > maxEdgeCount || (m[edgeDestiation] == maxEdgeCount && edgeDestiation < maxVertex)) {
                maxVertex = edgeDestiation;
                maxEdgeCount = m[edgeDestiation];
            }
        }

        return maxVertex;
    }
};