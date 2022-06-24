#include <vector>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;
        const int& kth_amount = tickets[k];
        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                total += min(tickets[i], kth_amount);
            } else {
                total += min(tickets[i], kth_amount-1);
            }
        }
        return total;
    }
};

// V2: slightly more efficient:
#include <vector>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;
        const int& kth_amount = tickets[k];
        for (int i = 0; i < tickets.size(); ++i) {
                total += min(tickets[i], kth_amount - (i > k));
        }
        return total;
    }
};