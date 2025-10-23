#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Dp: the max sum at idx i
        vector<int> dp(nums.size()+1, 0);
        int Cur = nums[0];
        dp[0] = nums[0];

        for (int i=1; i<nums.size(); i++) {
            // Start new at idx i or add to the existing sum
            Cur = max(nums[i], Cur+nums[i]);
            dp[i] = max(dp[i-1], Cur);
        }
        return dp[nums.size()-1];
    }
};