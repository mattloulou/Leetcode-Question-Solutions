#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    // we need to know the last house where each type of garbage occurs, and also the count of each
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> garbageCounts(3); // MPG
        vector<int> garbageTypeLastSeen(3); // the house index where they were last seen. MPG is the order. 0 is if there were no sightings, or if it was just at the first house (same thing since both mean no travel).
        vector<char> garbageTypeOrder{'M','P','G'};
        
        for (int i = garbage.size()-1; i >= 0; --i) {
            unordered_map<char, int> currentGarbageCounts;
            for (const char& c : garbage[i]) {
                ++currentGarbageCounts[c];
            }
            
            for (int type = 0; type < garbageTypeOrder.size(); ++type) {
                if (!garbageTypeLastSeen[type] && currentGarbageCounts.count(garbageTypeOrder[type])) {
                    garbageTypeLastSeen[type] = i;
                } 
                garbageCounts[type] += currentGarbageCounts[garbageTypeOrder[type]];
            }
        }
        
        // account for the amount of garbage to be picked up
        int result = accumulate(garbageCounts.begin(), garbageCounts.end(), 0);
        
        // account for travel
        for (int type = 0; type < garbageTypeOrder.size(); ++type) {
            result += (garbageTypeLastSeen[type] == 0) ? 0: accumulate(travel.begin(), travel.begin() + garbageTypeLastSeen[type], 0);
        }
        
        return result;
        
    }
};