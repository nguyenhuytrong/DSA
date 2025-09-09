#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for (string s : strs) {
            // Count letters
            vector<int> cnt(26, 0);
            for (char c : s) {
                cnt[c - 'a']++;
            }

            // Convert count vector to a key string
            string key;
            for (int x : cnt) {
                key += to_string(x) + "#"; 
            }

            ans[key].push_back(s);  
        }
        // Collect result
        vector<vector<string>> res;
        for (auto& [k, group] : ans) {
            res.push_back(group);
        }
        return res;
    }
};