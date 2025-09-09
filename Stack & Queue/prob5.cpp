#include<bits/stdc++.h>
using namespace std;
/*
Idea: 
- Cày trâu: với mỗi độ cao của hcn (h[i]), xét xem độ cao đó có thể expand về 2 phía
xa nhất tới đâu 
---> Tính được maxArea. Tuy nhiên, complexity: O(n^2)
- Tối ưu: lưu chuỗi index sao cho h tăng dần, khi gặp một idx i thấp hơn, ta biết rằng 
diện tích không thể expand (về bên phải) tiếp nữa. Ta tính ngược lại maxArea với chiều cao
của từng h trong chuỗi vừa lưu, đến khi gặp h < h[i]. 
---> Dùng stack để pop lần lượt các h cần xét.
*/

// Solution 1
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st; // index, height
        for (int i=0; i< heights.size(); i++) {
            int start = i;
            while (!st.empty() && heights[i] < st.top().second) {
                auto [index, height] = st.top();
                st.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            st.emplace(start, heights[i]);
        }
        
        int n = heights.size();
        while(!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            maxArea = max(maxArea, height * (n - index));
        }
        
        return maxArea;
    }
};
*/
// Solution 2
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // store the index
        int res = 0;
        int i = 0;
        while (i<heights.size()) {
            // If empty or maxArea can be expanded to the right column
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i);
                i++;
            }
            else {
                // Can't expand, calculate the maxArea
                int idx = st.top();
                st.pop();
                if (st.empty()) res = max(res, i * heights[idx]);
                else res = max(res, heights[idx]*(i -st.top() -1));
            }
        }

        // Some 
        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            if (st.empty()) res = max(res, i * heights[idx]);
            else res = max(res, heights[idx]*(i -st.top() -1));
        }

        return res;
    }   
};

int main() {
    Solution sol;

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = sol.largestRectangleArea(heights);
    cout << "Result: " << result << endl;  // Expected: 10

    return 0;
}