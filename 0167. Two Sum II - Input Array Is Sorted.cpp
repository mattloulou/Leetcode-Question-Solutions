#include <vector>
#include <unordered_map>
using namespace std;

//V1: 0001. Two Sum.cpp solution.
// uses a map. Doesn't take advantage of the sorted property
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> numbers_seen;
        for (int i = 0; i < numbers.size(); ++i) {
            const int& num = numbers[i];
            const int other_num = target-num;
            if (numbers_seen.count(other_num)) {
                return vector<int>{numbers_seen.at(other_num) + 1, i + 1}; // since the indexing begins at 1, not 0.
            } else {
                numbers_seen.insert({num, i}); 
            }
        }      
        return vector<int>(); // should never reach based on question specifications
    }
};

//V2 uses two 'pointers'. Takes advantage of the sorted property
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int first = 0;
        int last = numbers.size()-1;

        while (numbers[first] + numbers[last] != target) {
            const int sum = numbers[first] + numbers[last];
            if (sum > target) {
                --last;
            } else {
                ++first;
            }
        }
        return vector<int>{first + 1, last + 1}; // `+ 1` is because the indexing begins at 1, not 0.
    }
};