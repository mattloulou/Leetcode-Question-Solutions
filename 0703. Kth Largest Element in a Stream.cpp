#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // greater<int> means it is going top() --> 0,1,2,3,4,5,.... We always want the kth largest to be at pq.top()
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k{k} {
        for (const int& n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */