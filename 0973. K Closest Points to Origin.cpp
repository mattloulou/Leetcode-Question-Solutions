#include <vector>
#include <queue>
using namespace std;
using PairType = pair<int,vector<int>>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        //this creates a PQ sorted reversely (default is highest priority first, but we want the smallest PairType (which will be based on the int) first).
        //param1 is PairType. Since we can only make a PQ sort single instances of objects (not priority + an object), we must make them pairs
        //param2 is required so that we can set param3
        //param3 is a function that sets the comparison to presumably be opposite of normal (since stackoverflow says it will sort smallest first https://stackoverflow.com/a/15647215)
        //note that for PairType = pair<int,vector<int>>, as it is a pair, in comparisons, it will compare pair.first preliminarily, then pair.second if needed
        priority_queue<PairType, vector<PairType>, std::greater<PairType>> points_sorted_by_distance;

        //Go through each given coordinate and insert a pair into the PQ of (distance, coordinate). 
        //Note that for distance we can forgo sqrt(), as order is preserved. This lets us use an int instead of a double! 
        for (const vector<int>& coordinate : points) {
            points_sorted_by_distance.emplace(coordinate[0]*coordinate[0] + coordinate[1]*coordinate[1], coordinate);
        }

        vector<vector<int>> answer(k);

        //take the top k pairs
        for (int i = 0; i < k; ++i) { //MISTAKE: originally I had an annoying bug here where in the third part, I did `++k` not `++i`
            answer.at(i) = points_sorted_by_distance.top().second;
            points_sorted_by_distance.pop();
        }
        return answer;
    }
};