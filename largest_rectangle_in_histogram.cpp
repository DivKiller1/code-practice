// Problem: Largest Rectangle in Histogram
// Difficulty: Hard
// Topic: stack
//
// Description: Given an array of integers representing the bar heights in a histogram,
// calculate the area of the largest rectangle that can be formed within the histogram.
// Example Input: 6\n2 1 5 6 2 3
// Example Output: 10

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long getMaxArea(const vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    long long maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] > currentHeight) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, (long long)h * width);
        }
        st.push(i);
    }

    return maxArea;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << getMaxArea(heights) << "\n";

    return 0;
}
