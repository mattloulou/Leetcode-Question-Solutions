#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (needle.size() > haystack.size()) return -1; // this is required because the loop will use an unsigned scalar type, which would overflow to a massive num.
        for (int haystack_index = 0; haystack_index <= haystack.size() - needle.size(); ++haystack_index) {
            if (haystack.substr(haystack_index, needle.size()) == needle) {
                return haystack_index;
            }
        }
        return -1;
    }
};