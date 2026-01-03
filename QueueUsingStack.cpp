#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty())
            transfer();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        if (outStack.empty())
            transfer();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    cout << myQueue.peek() << endl; // 1
    cout << myQueue.pop() << endl;  // 1
    cout << myQueue.empty() << endl; // false
    return 0;
}
