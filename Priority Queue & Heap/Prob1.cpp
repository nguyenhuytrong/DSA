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

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i : nums) freq[i]++;

        int rows = nums.size() + 1;
        vector<list<int>> buckets(rows);
        for (auto [num, count] : freq) {
            buckets[count].push_back(num);  // tần suất => index
        }
        
        vector<int> res;
        for (int i = nums.size(); i >= 0 && res.size() < k; i--) {
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    res.push_back(num);
                    if (res.size() == k) break;
                }
            }
        }

        return res;
    }
};

