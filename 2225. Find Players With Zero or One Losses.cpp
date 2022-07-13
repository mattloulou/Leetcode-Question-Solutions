#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> noLoss;
        set<int> oneLoss;
        unordered_set<int> seenBefore;
        for (const vector<int>& v : matches) {

            //if the winner has not won before, add them to the list
            if (!seenBefore.count(v[0])) {
                noLoss.insert(v[0]);
                seenBefore.insert(v[0]);
            }
            

            // if the loser has not been seen before
            if (!seenBefore.count(v[1])) {
                oneLoss.insert(v[1]);
                seenBefore.insert(v[1]);

            // if the loser has been seen but never lost yet
            } else if (noLoss.count(v[1])) {
                noLoss.erase(v[1]);
                oneLoss.insert(v[1]);
            
            // if the loser has lost just once before
            } else if (oneLoss.count(v[1])) {
                oneLoss.erase(v[1]);
            }
        }

        return {vector<int>(noLoss.begin(), noLoss.end()), vector<int>(oneLoss.begin(), oneLoss.end())};

    }
};