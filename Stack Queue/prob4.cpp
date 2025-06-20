#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        // Xử lý chuỗi s
        for (char x : s) {
            if (x != '#') s1.push(x);
            else if (!s1.empty()) s1.pop();
        }

        // Xử lý chuỗi t
        for (char x : t) {
            if (x != '#') s2.push(x);
            else if (!s2.empty()) s2.pop();
        }

        // So sánh 2 stack
        if (s1.size() != s2.size()) return false;

        while (!s1.empty()) {
            if (s1.top() != s2.top()) return false;
            s1.pop();
            s2.pop();
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "ab#c";
    string t1 = "ad#c";
    cout << boolalpha << "Compare(\"" << s1 << "\", \"" << t1 << "\") = " 
         << sol.backspaceCompare(s1, t1) << endl;  // true

    // Test case 2
    string s2 = "ab##";
    string t2 = "c#d#";
    cout << "Compare(\"" << s2 << "\", \"" << t2 << "\") = " 
         << sol.backspaceCompare(s2, t2) << endl;  // true

    // Test case 3
    string s3 = "a#c";
    string t3 = "b";
    cout << "Compare(\"" << s3 << "\", \"" << t3 << "\") = " 
         << sol.backspaceCompare(s3, t3) << endl;  // false

    return 0;
}
