#include<bits/stdc++.h>
using namespace std;

class Solution1 {
private:
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i : nums) freq[i]++;

        priority_queue<pair<int, int>> pq;
        for (auto [num, val] : freq) pq.push({val, num});

        vector<int> res;
        int n = pq.size();
        while (k--) {
            res.push_back(pq.top().second);  
            pq.pop();
        }
        return res;   
    }
};

