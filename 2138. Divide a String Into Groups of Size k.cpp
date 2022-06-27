#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int index = 0;
        vector<string> answer;
        while (index < s.size()) {
            const int chars_left = s.size()-index;
            if (chars_left >= k) {
                answer.push_back(s.substr(index, k));
            } else {
                answer.push_back(s.substr(index));
                for (int i = 0; i < k - chars_left; ++i) {
                    answer.back().push_back(fill);
                }
            }
            index += k;
        }
        return answer;

    }
};

//V2 Better solution by Hargun
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> answer;
        // while (s.size()%k != 0) {
        //     s.push_back(fill);
        // }

        if (s.size() %k ) {
            string ammendment(k - (s.size()%k), fill);
            s += ammendment;
        }

        for (int i = 0; i < s.size(); i += k) {
            answer.push_back(s.substr(i,k));
        }
        return answer;

    }
};