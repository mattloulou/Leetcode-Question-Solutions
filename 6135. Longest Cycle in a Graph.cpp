#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int maxCycleSize = -1;
        unordered_set<int> nodesAnalyzed; // {int} is the starting node of that cycle.

        for (int i = 0; i < edges.size(); ++i) {
            if (nodesAnalyzed.count(i)) continue;

            int currentPosition = 0;
            int currentNode = i;
            unordered_map<int, int> nodePositionSeen; // {node number, what step they were seen in (first, second, third, etc)}

            // keep searching until we hit a dead end
            while (!nodesAnalyzed.count(currentNode)) {
                nodesAnalyzed.insert(currentNode);
                nodePositionSeen.insert({currentNode, currentPosition});
                ++currentPosition;
                if (edges[currentNode] != -1) {
                    currentNode = edges[currentNode];
                } else {
                    break;
                }
            }

            // figure out the length of the cycle found, if any. currentNode is the last node visited before finding a cycle, or a dead end.

            // if `nodePositionSeen.count(edges[currentNode])`, then we have a cycle.
            if (nodePositionSeen.count(edges[currentNode])) {
                const int currentCycleLength = currentPosition - nodePositionSeen.at(edges[currentNode]) + 1;
                maxCycleSize = max(maxCycleSize, currentCycleLength);
            }
        }    

        return maxCycleSize;  
    }


};