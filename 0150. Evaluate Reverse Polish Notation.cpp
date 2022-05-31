#include <vector>
#include <string>
#include <list>
#include <cctype>
#include <iostream>
using namespace std;

//V1 bad solution
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        list<string> list_tokens(tokens.begin(), tokens.end());
        auto it = list_tokens.begin();
        
        while (list_tokens.size() > 1) {

            //NOTE: *it will always be a number. In this algorithm it will never arrive at an operation.

            auto next_it = it;
            ++next_it;
            auto next_next_it = next_it;
            ++next_next_it;
            
            //if an operation can be performed, do so, and remove the used up tokens.
            if (isStringNumber(*next_it) && !isStringNumber(*next_next_it)) {
                const string operation = *next_next_it;
                if (operation == "+") {
                    *it = to_string(stoi(*it) + stoi(*next_it));
                } else if (operation == "-") {
                    *it = to_string(stoi(*it) - stoi(*next_it));
                } else if (operation == "*") {
                    *it = to_string(stoi(*it) * stoi(*next_it));
                } else {
                    *it = to_string(stoi(*it) / stoi(*next_it));
                }
                //erase the two tokens used up.
                ++next_next_it;
                list_tokens.erase(next_it, next_next_it);

            //if our current iterator is right before an operator, back up so we can use it
            } else if (!isStringNumber(*next_it)) {
                --it;

            //otherwise, we just have a bunch of numbers available, so we move forward.
            } else {
                ++it;
            }
        }
        return stoi(*list_tokens.begin());
    }

    // this is by the standards of the question. Numbers will have multiple chars, and/or the first will be a digit.
    // This takes into account that there can be negative numbers,
    bool isStringNumber(const string& str) {
        return str.size() > 1 || isdigit(str[0]);
    }
};

//V2 much better solution by Hargun M.
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string back = tokens.back();
        tokens.pop_back();
        if(back == "*" || back == "/" || back == "+" || back == "-"){
            int right = evalRPN(tokens);
            int left = evalRPN(tokens);
            if (back == "*") return left * right;
            else if(back == "/") return left / right;
            else if(back == "+") return left + right;
            else return left - right;
        }
        else return stoi(back);
        
    }
};