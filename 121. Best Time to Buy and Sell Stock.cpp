#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

    //solution logic: At any given i^th day (each index in prices), the best price you can get is "prices.at(i) - all_time_low_up_until_day_i"

        int min = prices.at(0);
        int max_profit = 0;

        //loop through each element and keep updating the minimum price, and compare it to the current value.
        for (int i = 1; i < prices.size(); ++i) {
            
            //check if we have a new min
            if (prices.at(i) < min) {
                min = prices.at(i);
            }

            const int current_profit = prices.at(i) - min;
            max_profit = current_profit > max_profit ? current_profit: max_profit;
        }
        
        return max_profit;
    }


};