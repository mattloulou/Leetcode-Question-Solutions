#include<string>
#include<unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map{{'{','}'}, {'[',']'}, {'(',')'}};
        stack<char> inputs;
        for (const char& c : s) {

            //if c is an open bracket
            if (map.count(c)) {
                inputs.push(c);

            //if c is a closing bracket
            } else {

                // if the stack is empty, then we can't be closing.
                if (inputs.size() == 0) {
                    return false;
                }

                //if it properly closes a bracket
                else if (map.at(inputs.top()) == c) {
                    inputs.pop();
                } else {
                    return false;
                }
            }
        }
        //check if all brackets were properly closed
        return inputs.empty();
    }
};