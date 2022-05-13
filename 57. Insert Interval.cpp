#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> answer;
        int merged_interval_start = newInterval[0]; 
        int merged_interval_end = newInterval[1];
        bool has_inserted_merged_interval = false;
        for (const vector<int>& interval : intervals) {
            
            //case 1, the interval is completely before the newInterval
            if (interval[1] < merged_interval_start) {
                answer.emplace_back(interval);
            
            //case 2, the interval is completely after the newInterval
            } else if (interval[0] > merged_interval_end) {
                
                //it is now time to add our newly merged new-interval
                if (!has_inserted_merged_interval) {
                    answer.emplace_back(vector<int>{merged_interval_start, merged_interval_end});
                    has_inserted_merged_interval = true;
                }
                answer.emplace_back(interval);
            }

            //case 3, they overlap
            else {
                merged_interval_start = min(merged_interval_start, interval[0]);
                merged_interval_end = max(merged_interval_end, interval[1]);
            }
        }

        //add our new interval in case it has not yet been added
        if (!has_inserted_merged_interval) {
            answer.emplace_back(vector<int>{merged_interval_start, merged_interval_end});
        }

        return answer;

    }
};