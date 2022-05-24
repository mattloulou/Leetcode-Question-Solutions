#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int> solution(queries.size(), 0);

        //loop through each query
        for (int query_index = 0; query_index < queries.size(); ++query_index) {
            int& points_inside_count = solution[query_index];
            const vector<int>& query = queries[query_index];

            //loop through each point
            for (const vector<int>& point : points) {

                //check if the distance between the query-centre and the given coordinate-point is less than the radius
                const int x_distance = query[0] - point[0];
                const int y_distance = query[1] - point[1];
                if ( x_distance*x_distance + y_distance*y_distance <= query[2]*query[2]) { //MISTAKE: at first I forgot to square query[2]
                    ++points_inside_count;
                }
            }
        }
        return solution;
    }
};