#include <vector>
#include <unordered_map>
#include <algorithm>
// #include <iostream>
using namespace std;

//solution learned from https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C%2B%2B-solution-around-50ms-O(N*N)-with-explanation-and-comments
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {

        sort(num.begin(), num.end());
        vector<vector<int>> solution;

        for (int i = 0; i < num.size(); ++i) {


            //in each iteration, we are using an approach to 2-sum.
            //we begin with a front and back index to the remaining range, and keep trying to home in on pairs of numbers that match this target.
            //Pairs will always be sanwiched between each other.
            const int target = -num[i];
            int front = i+1;
            int back = num.size()-1;
            
            while (front < back) {

                const int sum = num[front] + num[back];

                //sum is too small, so move the front index forward to increase the sum
                if (sum < target) {
                    ++front;

                //sum is too large, so move the back index backwards.
                } else if (sum > target) {
                    --back;
                
                //here we have a sum matching the target.
                } else {
                    vector<int> triple{num[i], num[front], num[back]};
                    solution.emplace_back(triple);

                    //move the front and back indices inwards towards a future potential pair
                    const int front_val = num[front];
                    const int back_val = num[back];
                    while (front < back && num[front] == front_val) ++front;
                    while (front < back && num[back] == back_val) --back;
                }
            }

            //we are now skipping past duplicate values for num[i]. Don't forget our for loop already increments i.
            //so, we just want to go until the next element is different from the current one.
            const int i_value = num[i];
            while (i < num.size()-1 && num[i+1] == i_value) ++i;
        }

        return solution;
    }
};