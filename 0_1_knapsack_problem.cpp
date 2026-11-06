// Problem: 0/1 Knapsack Problem
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given N items with specific weights and values, find the maximum total value that can fit into a knapsack of capacity W.
// Example Input: N = 4, W = 5, items = [(2,3), (1,2), (3,4), (2,4)]
// Example Output: 9

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, capacity;
    if (!(cin >> n >> capacity)) {
        return 0;
    }

    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = capacity; w >= weights[i]; --w) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    cout << dp[capacity] << "\n";

    return 0;
}
