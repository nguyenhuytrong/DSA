#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        for (int i=0; i<score.size(); i++) {
            pq.push({score[i], i});
        }

        int n = score.size();
        vector<string> res(n);

        if (!pq.empty()) {
            res[pq.top().second] = "Gold Medal"; pq.pop();
        }
        if (!pq.empty()) {
            res[pq.top().second] = "Silver Medal"; pq.pop();
        }
        if (!pq.empty()) {
            res[pq.top().second] = "Bronze Medal"; pq.pop();
        }

        int rank = 4;
        while (!pq.empty()) {
            res[pq.top().second] = to_string(rank);
            pq.pop();
            rank++;
        }
        return res;
    }
};