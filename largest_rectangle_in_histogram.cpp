// Problem: Largest Rectangle in Histogram
// Difficulty: Hard
// Topic: stack
//
// Description: Given an array of integers representing the heights of histogram bars where the width of each bar is 1, find the area of the largest rectangle that can be formed within the histogram.
// Example Input: 6 \n 2 1 5 6 2 3
// Example Output: 10

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long getMaxArea(const vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    long long max_area = 0;

    for (int i = 0; i <= n; i++) {
        int current_height = (i == n) ? 0 : heights[i];
        
        while (!st.empty() && heights[st.top()] >= current_height) {
            int h = heights[st.top()];
            st.pop();
            
            int w = st.empty() ? i : (i - st.top() - 1);
            max_area = max(max_area, (long long)h * w);
        }
        
        st.push(i);
    }

    return max_area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        cout << getMaxArea(heights) << endl;
    }

    return 0;
}
