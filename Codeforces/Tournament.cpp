#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        if (k > 1) {
            cout << "YES\n";
        } else {
            int pj = a[j - 1];
            int max_a = *max_element(a.begin(), a.end());
            if (pj == max_a) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}