// Problem: 0-1 Knapsack Problem
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given weights and values of N items, determine the maximum total value that can be obtained in a knapsack of capacity W.
// Example Input: 3 50\n60 10\n100 20\n120 30
// Example Output: 220

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

    vector<int> values(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    // dp[w] stores the maximum value achievable with capacity w
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    cout << dp[capacity] << "\n";

    return 0;
}
