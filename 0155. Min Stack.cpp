#include <vector>
using namespace std;

//V2 from solution: https://leetcode.com/problems/min-stack/discuss/1209254/C%2B%2B-Simple-code-with-one-stack
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if (this->stack.empty()) {
            stack.push_back(pair<int,int>(val,val));
        } else {
            stack.push_back(pair<int,int>(val,min(val,stack.back().second)));
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
private:
    vector<pair<int,int>> stack; //{node value, min seen up until this point}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */