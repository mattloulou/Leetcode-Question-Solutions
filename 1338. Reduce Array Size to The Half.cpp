#include <vector>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {

        // first, find the occurances of each element in arr
        unordered_map<int, int> elementOccurances; // {element in arr, occurances}
        for (const auto& n : arr) {
            ++elementOccurances[n];
        }

        map<int,int, greater<int>> occuranceCounts; // {occurance, the number of times that this occurance appears within arr}
        for (const auto& p : elementOccurances) {
            ++occuranceCounts[p.second];
        }

        int elementsLeftToRemove = arr.size()/2 + (arr.size()%2 != 0); // divide by 2 and round up

        int answer = 0;
        for (const auto& p : occuranceCounts) {
            const int currentOccuranceCountRequired = elementsLeftToRemove/p.first + (elementsLeftToRemove%p.first != 0); // divide elementsLeftToRemove by the occurance
            if (p.second >= currentOccuranceCountRequired) {
                return answer + currentOccuranceCountRequired;
            } else {
                answer += p.second; // we remove `p.second` more integers
                elementsLeftToRemove -= p.first * p.second; // we have then removed p.first*p.second elements from `arr`
            }
        }
        return 0; // should never happen
    }
};