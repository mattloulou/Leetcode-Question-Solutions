#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1), v2(version2);
        string v1segment, v2segment;
        int v1val, v2val;
        while (true) {
            v1val = (getline(v1,v1segment,'.')) ? stoi(v1segment): 0;
            v2val = (getline(v2,v2segment,'.')) ? stoi(v2segment): 0;
            if (v1val > v2val) return 1;
            if (v1val < v2val) return -1;
            if (!v1 && !v2) return 0;
        }
        return 0;
    }
};