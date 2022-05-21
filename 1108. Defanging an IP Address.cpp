#include <string>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        int index = 0;
        while (true) {
            index = address.find('.',index);
            if (index == string::npos) return address;
            address.replace(index, 1, "[.]");
            index += 3;
        }
    }
};