// Problem: Largest Rectangle in Histogram
// Difficulty: Hard
// Topic: stack
//
// Description: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, find the area of the largest rectangle in the histogram.
// Example Input: 6 2 1 5 6 2 3
// Example Output: 10

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<long long> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    stack<int> st;
    long long maxArea = 0;

    for (int i = 0; i <= n; i++) {
        long long currentHeight = (i == n) ? 0 : heights[i];
        while (!st.empty() && currentHeight < heights[st.top()]) {
            long long h = heights[st.top()];
            st.pop();
            long long width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    cout << maxArea << "\n";

    return 0;
}
