#include<bits/stdc++.h>
using namespace std;    

// Rolling hash approach to find the shortest palindrome by checking prefixes and suffixes
// Runtime Error
class Solution1 {
public:
    string shortestPalindrome(string s) {
        long long prefix = 0, suffix = 0;
        long long base = 29;
        long long mod = 1000000007;
        long long power = 1;
        int last_idx = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a' + 1;
            // hash xuôi
            prefix = ( (__int128)prefix * base + c ) % mod;
            // hash ngược
            suffix = ( suffix + (__int128)c * power ) % mod;
            power = ( (__int128)power * base ) % mod;
            if (prefix == suffix) {
                last_idx = i;
            }
        }

        string suffix_str = s.substr(last_idx + 1);
        reverse(suffix_str.begin(), suffix_str.end());
        return suffix_str + s;
    }
};

// KMP approach to find the shortest palindrome by checking prefixes and suffixes
class Solution2 {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        string combined = s + "#" + rev;
        int n = combined.size();
        
        // Build LPS array
        vector<int> lps(n, 0);
        int i = 1, j = 0;
        while (i < n) {
            if (combined[i] == combined[j]) {
                lps[i] = j + 1;
                j++;
                i++;
            } 
            else if (combined[i] != combined[j] && j > 0) {
                j = lps[j - 1];
            } 
            else {
                lps[i] = 0;
                i++;
            }
        }
        // Length of longest palindrome prefix
        int longest = lps[n - 1];
        // Add remaining suffix (from reversed) in front
        return rev.substr(0, s.size() - longest) + s;
    }
};

