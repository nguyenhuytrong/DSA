#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> reward1(n), reward2(n);

    for (int i = 0; i < n; i++) cin >> reward1[i];
    for (int i = 0; i < n; i++) cin >> reward2[i];

    vector<pair<int,int>> diff;
    for (int i = 0; i < n; i++) {
        diff.push_back({reward1[i] - reward2[i], i});
    }

    sort(diff.begin(), diff.end(), greater<>());

    int res = 0;
    for (int i = 0; i < k; i++) {
        int idx = diff[i].second;
        res += reward1[idx];
    }

    for (int i = k; i < n; i++) {
        int idx = diff[i].second;
        res += reward2[idx];
    }

    cout << res << endl;
    return 0;
}
