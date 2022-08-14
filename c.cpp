#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

// I will use a greedy approach
// we will always begin with 1. When I increase, I go to the next available integer above the previous
// when I have to decrease, I increment the previous digits which are >= the last existing one, and then the new one will be what the previous one was.
class Solution {
public:
    string smallestNumber(string pattern) {
        vector<char> num(pattern.size()+1, 1);
        int index = 1;
        for (auto c : pattern) {
            if (c == 'I') {
                num[index] = index+1;
            } else {
                int previousMax = num[index-1];
                for (char& n : num) {
                    if (n >= previousMax) ++n;
                }
                num[index] = previousMax;
            }
            ++index;
        }

        // convert num into a string
        string result;
        for (auto i : num) {
            result.push_back('0'+i);
        }
        return result;

    }
};