#include<bits/stdc++.h>
#include<stack>
using namespace std;

class MyStack { 
private:
    queue<int> q; 
public:
    MyStack() {

    }

    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i=0; i < sz-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    cout << "Top: " << st.top() << endl; // Should print 20
    cout << "Pop: " << st.pop() << endl; // Should remove 20
    cout << "Empty? " << (st.empty() ? "Yes" : "No") << endl; // Should be No
    return 0;
}