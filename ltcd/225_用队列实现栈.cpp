#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() { }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int q_size = q.size();
        q_size--;
        while (q_size--) {
            int q_front = q.front();
            q.push(q_front);
            q.pop();
        }
        
        int res = q.front();
        q.pop();
        return res;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */