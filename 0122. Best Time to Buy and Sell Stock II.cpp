#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int boughtPrice = prices[0];

        // if the price goes up, always sell it and buy it again. If it goes down, change the buy price to the current one
        for (int i = 0; i < prices.size(); ++i) {
            const int& currentPrice = prices[i];
            if (currentPrice > boughtPrice) {
                totalProfit += currentPrice - boughtPrice;
            }
            boughtPrice = currentPrice;
        }

        return totalProfit;
    }
};