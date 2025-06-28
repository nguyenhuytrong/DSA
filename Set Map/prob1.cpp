#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hashset;
        for (int i=0; i<nums.size(); i++) {
            if (hashset.count(nums[i]) > 0) return true;
            hashset.insert(nums[i]); 
        }
        return false;
    }
};