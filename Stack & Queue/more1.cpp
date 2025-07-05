// Next greater generation
// 3 4 2 5 1 6 2
// 4 5 5 6 6 -1 -1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n], res[n];
    for (int &x : a) cin >> x;
    stack<int> st;
    for (int i=0; i<n; i++) {
        if (st.empty()) st.push(i);
        else {
            while (!st.empty() && a[st.top()] < a[i]) {
                res[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        res[st.top()] = -1;
        st.pop();
    }

    for (int &x : res) cout << x << " ";
}