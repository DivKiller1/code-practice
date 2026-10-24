// Problem: Largest Rectangle in Histogram
// Difficulty: Hard
// Topic: stack
//
// Description: Given an array of heights representing a histogram where each bar has width 1,
// compute the area of the largest rectangle that can be formed within the histogram.
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
    if (!(cin >> n)) return 0;

    vector<long long> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    stack<int> st;
    long long max_area = 0;

    for (int i = 0; i <= n; i++) {
        long long current_height = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] >= current_height) {
            long long h = heights[st.top()];
            st.pop();
            long long w = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, h * w);
        }
        st.push(i);
    }

    cout << max_area << "\n";

    return 0;
}
