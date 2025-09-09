#include <bits/stdc++.h>
using namespace std;

// FIrst try: TLE 
class FirstTry {
private: 
int MOD = 998244353;
int hash_func(const string& sub) {
    long long hash = 0;
    long long base = 26;  
    long long power = 1;

    for (int i = 0; i < (int)sub.size(); i++) {
        int val = sub[i] - 'a' + 1;
        hash = (hash + val * power) % MOD;
        power = (power * base) % MOD;
    }
    return (int)hash;
}
public:
    string longestDupSubstring(string s) {
        string ans = "";
        int lo = 1, hi = s.length(); // độ dài tối thiểu = 1

        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            unordered_map<int, int> cnt;
            bool found = false;
            string cur = "";

            for (int i = 0; i <= (int)s.length() - mid; i++) {
                string sub = s.substr(i, mid);
                int temp = hash_func(sub);

                if (cnt.find(temp) != cnt.end()) {
                    // xác minh để tránh collision
                    if (s.substr(cnt[temp], mid) == sub) {
                        found = true;
                        cur = sub;
                        break;
                    }
                } else {
                    cnt[temp] = i; // lưu vị trí lần đầu
                }
            }

            if (found) {
                if (cur.size() > ans.size()) ans = cur;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

// Solution with Rolling Hash and Binary Search
class Solution {
    using int64 = long long;
    const int64 MOD = 1000000007;
    const int64 BASE = 911382323; // base lớn để giảm collision
    
    vector<int64> pref, power;

    // build prefix hash
    void build(const string& s) {
        int n = s.size();
        pref.assign(n+1, 0);
        power.assign(n+1, 1);
        for (int i = 0; i < n; i++) {
            pref[i+1] = (pref[i]*BASE + (s[i]-'a'+1)) % MOD;
            power[i+1] = (power[i]*BASE) % MOD;
        }
    }

    // hash of substring s[l..r) (0-based, [l, r))
    int64 get(int l, int r) {
        int64 h = (pref[r] - (pref[l]*power[r-l])%MOD + MOD) % MOD;
        return h;
    }

public:
    string longestDupSubstring(string s) {
        int n = s.size();
        build(s);

        int lo = 1, hi = n, bestLen = 0, bestPos = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            unordered_map<int64, vector<int>> seen;
            bool found = false;
            int pos = -1;

            for (int i = 0; i+mid <= n; i++) {
                int64 h = get(i, i+mid);
                if (seen.count(h)) {
                    // verify against previous positions
                    for (int j : seen[h]) {
                        if (s.compare(i, mid, s, j, mid) == 0) {
                            found = true;
                            pos = i;
                            break;
                        }
                    }
                    if (found) break;
                }
                seen[h].push_back(i);
            }

            if (found) {
                if (mid > bestLen) {
                    bestLen = mid;
                    bestPos = pos;
                }
                lo = mid+1; // thử dài hơn
            } else {
                hi = mid-1; // giảm độ dài
            }
        }

        if (bestPos == -1) return "";
        return s.substr(bestPos, bestLen);
    }
};
