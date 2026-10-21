// Problem: 0/1 Knapsack Problem
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given weights and values of N items and a knapsack capacity W, find the maximum value subset of items such that total weight does not exceed W.
// Example Input: 3 50 \n 10 20 30 \n 60 100 120
// Example Output: 220

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
    if (!(cin >> n >> w)) {
        return 0;
    }

    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // dp[j] stores the maximum value achievable with maximum capacity j
    vector<int> dp(w + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = w; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp[w] << "\n";

    return 0;
}
