#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1 = process(s);
        stack<char> s2 = process(t);
        return s1 == s2;
    }
private: 
    stack<char> process(string str) {
        stack<char> stack;
        for (char &x : str) {
            if (x != '#') stack.push(x);
            else if (!stack.empty()) stack.pop();
        }

        return stack;
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
