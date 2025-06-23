#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
stack<int> st1;
stack<int> st2;
public:
MyQueue() {}
void push(int x) {
    st1.push(x);
}
int pop() {
    if (st2.empty()) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }
    int val = st2.top();
    st2.pop();
    return val;
}
int peek() {
    if (st2.empty()) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }
    return st2.top();    
}
bool empty() {
    return st1.empty() && st2.empty();
}
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    cout << "Peek: " << q.peek() << endl;   // Output: 1
    cout << "Pop: " << q.pop() << endl;     // Output: 1
    cout << "Empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: No

    q.pop();  // remove 2
    cout << "Empty after second pop? " << (q.empty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
