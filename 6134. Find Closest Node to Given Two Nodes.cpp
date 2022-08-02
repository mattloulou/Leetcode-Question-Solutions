#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// There will be a 'web' of nodes visited from both node1 and node2. We will take equal steps outwards from each, until we find an intersection. After completing that step,
// I will return the lowest value which is intersected between both nodes.
// I made a fundamental mistake when desinging, such that my algorithm works for graphs where nodes can have multiple edges, and not just one. This added extra complexity to it.
// It still passed though, so I kept it.
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        unordered_set<int> visited1;
        unordered_set<int> visited2;

        queue<int> q1;
        queue<int> q2;
        q1.push(node1);
        q2.push(node2);

        int answer = INT_MAX;

        while (!q1.empty() || !q2.empty()) {

            const int q1Size = q1.size();
            for (int i = 0; i < q1.size(); ++i) {
                const int q1top = q1.front();
                q1.pop();

                if (visited2.count(q1top)) {
                    answer = min(answer, q1top);
                }
                visited1.insert(q1top);
                if (edges[q1top] != -1 && !visited1.count(edges[q1top])) {
                    q1.push(edges[q1top]);
                }
            }
            
            const int q2Size = q2.size();
            for (int i = 0; i < q2.size(); ++i) {
                const int q2top = q2.front();
                q2.pop();
                
                if (visited1.count(q2top)) {
                    answer = min(answer, q2top);
                }
                visited2.insert(q2top);
                if (edges[q2top] != -1 && !visited2.count(edges[q2top])) {
                    q2.push(edges[q2top]);
                }
            }

            if (answer != INT_MAX) return answer;
        }

        return -1;
    }
};