#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> freq;
        vector<int> res;
        for (auto i : nums1) {
            freq[i] ++;
        }

        for (auto i: nums2) {
            if (freq[i] > 0) {
                res.push_back(i);
                freq[i] --;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0;
        while (i < nums1.size() and j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j]) {
                // Num1 > num2, so j must move forward so that nums2[j] >= nums1[i]
                int idx = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
                j = idx;
            }
            else {
                // Num1 < num2, so i must move forward so that nums1[i] >= nums2[j]
                int idx = lower_bound(nums1.begin(), nums1.end(), nums2[j]) - nums1.begin();
                i = idx;
            }
        }
        return res;
    }
};