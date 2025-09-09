#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
        // khởi tạo không cần gì thêm, queue tự động trống
    }

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

int main() {
    RecentCounter rc;
    cout << rc.ping(1) << endl;      // 1
    cout << rc.ping(100) << endl;    // 2
    cout << rc.ping(3001) << endl;   // 3
    cout << rc.ping(3002) << endl;   // 3
}