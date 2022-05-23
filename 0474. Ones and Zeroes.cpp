#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int answer = 0;
        vector<int> nums_remaining{m,n};
        vector<pair<int,int>> str_digit_counts;

        //loop through all strs and deal with the ones guaranteed to bring profit (single bit strings)
        for (const string& str : strs) {
            
            //if the string just has 1 char it will always be profitable to take it
            if (str.size() == 1 && nums_remaining.at(stoi(str)) > 0) {
                ++answer;
                --nums_remaining.at(stoi(str));

            //otherwise, we will simplify the form of data now.
            } else {
                int zero_count = 0;
                int one_count = 0;
                for (const char& c : str) {
                    if (c == '0') {
                        ++zero_count;
                    } else {
                        ++one_count;
                    }
                }
                if (zero_count <= nums_remaining[0] && one_count < nums_remaining[1]) {
                    str_digit_counts.emplace_back(zero_count, one_count);
                }
            }
        } 

        //now we have to deal with the remaining strings.










        return answer;
    }
};