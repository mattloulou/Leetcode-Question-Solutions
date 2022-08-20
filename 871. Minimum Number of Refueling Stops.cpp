#include <vector>
#include <queue>
using namespace std;


/* Algorithm: Greedy Approach
 * We want to first drive as far as we can with the current ballance of fuel. We also want to record which quantities of fuel we have passed as we drive. 
 * If we run out of fuel before making it to the end, we will modify the route so that we get fuel from the stop with the most amount of fuel (which has not been visited before).
 * 
 * Note that the stations are presorted in `stations` based on position (ascending)
 */

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> fuelAvailable; // contains just the fuel values of the stations we have passed so far.. Note that PQs will have the largest element at the top by default.
        
        int stopCount = 0;
        int stationIndex = 0;

        // setup with the initial starting fuel
        int currentDistance = startFuel;
        while (stationIndex < stations.size() && stations[stationIndex][0] <= currentDistance) {
            fuelAvailable.push(stations[stationIndex++][1]);
        }


        while (currentDistance < target && fuelAvailable.size() > 0) {
            
            // get some more fuel
            if (fuelAvailable.size() != 0) {
                currentDistance += fuelAvailable.top();
                fuelAvailable.pop(); // the largest amount of fuel available so far
                ++stopCount;
            }
            
            // see which new stations we have passed
            while (stationIndex < stations.size() && stations[stationIndex][0] <= currentDistance) {
                fuelAvailable.push(stations[stationIndex++][1]);
            }
        }

        if (currentDistance >= target) {
            return stopCount;
        } else {
            return -1;
        }
    }
};