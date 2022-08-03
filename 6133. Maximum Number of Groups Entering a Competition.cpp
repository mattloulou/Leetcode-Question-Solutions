#include <vector>
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int result = 0;
        while ((result * (result+1))/2 < grades.size()) {
            ++result;
        }
        return result - 1;
    }
};