#include <stack>
using namespace std;
class MyQueue {
public:

    //Design Plan:
    //basically, we will have two stacks of course. We will by default push things into the first stack.
    //The first stack is basically reverse order of the Queue, while the second stack is the correct order of the Queue.
    //If we want to take from the top of the Queue, we take from the top of the second stack (transfering the first to the second if it is empty)

    stack<int> first_stack{};
    stack<int> second_stack{};

    MyQueue() {}
    
    void push(int x) {
        first_stack.push(x);
    }
    
    int pop() {
        if (second_stack.empty()) {
            TransferFirstStackToSecond();
        }
        const int output = second_stack.top();
        second_stack.pop();
        return output;
    }
    
    int peek() {
        if (second_stack.empty()) {
            TransferFirstStackToSecond();
        }
        return second_stack.top();
    }
    
    bool empty() {
        return (first_stack.empty() && second_stack.empty());
    }

private:
    void TransferFirstStackToSecond() {
        while (!first_stack.empty()) {
            second_stack.push(first_stack.top());
            first_stack.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */