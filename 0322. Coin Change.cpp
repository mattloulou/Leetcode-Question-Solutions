#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int& amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());

        // data structure setup
        queue<int> values_to_check;
        unordered_map<int, int> amounts_reached; // {new_amount, coins_required_to_achieve}. amounts_reached is a map of `amount`s 
        values_to_check.push(amount);
        amounts_reached.insert({amount, 0});
        
        while (!values_to_check.empty()) {
            const int current_amount = values_to_check.front();
            values_to_check.pop();
            for (const int& coin : coins) {
                const int new_amount = current_amount - coin;
                if (new_amount == 0) {
                    return 1 + amounts_reached.at(current_amount);

                // since coins are sorted ascendingly, if one coin goes below 0, then the others will too.
                } else if (new_amount < 0) {
                    break;
                } else {

                    // if `new_amount` was not yet processed and `new_amount` is not smaller than the smallest coin:
                    if (!amounts_reached.count(new_amount) && new_amount >= coins[0]) {
                        values_to_check.push(new_amount);
                        amounts_reached.insert({new_amount, amounts_reached.at(current_amount) + 1});
                    }
                }
            }
        }

        return -1;
    }
};