#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> pos;   
        int fi = 0, se = 0, ans = 0;

        while (se < (int)s.size()) {
            char c = s[se];
            if (pos.count(c) && pos[c] >= fi) {
                fi = pos[c] + 1;            
            }
            pos[c] = se;
            ans = max(ans, se - fi + 1);
            se++;
        }
        return ans;
    }
};
