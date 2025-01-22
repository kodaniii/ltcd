#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stackIn;
    stack<int> stackOut;
public:
    MyQueue() {}

    void push(int x) {
        stackIn.push(x);
    }

    int pop() {
        if (stackOut.empty()) {
            while (!stackIn.empty()) {
                int ele = stackIn.top();
                stackIn.pop();
                stackOut.push(ele);
            }
        }

        int res = stackOut.top();
        stackOut.pop();
        
        return res;
    }

    int peek() {
        int top_ele = pop();
        stackOut.push(top_ele);
        return top_ele;
    }

    bool empty() {
        return stackIn.empty() && stackOut.empty();
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