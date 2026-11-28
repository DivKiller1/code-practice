// Problem: 0/1 Knapsack Problem
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given weights and values of N items, determine the maximum total value that can be placed in a knapsack of capacity W. Each item can either be chosen or not.
// Example Input: 3 5\n1 2 3\n10 15 40
// Example Output: 55

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w;
    if (!(cin >> n >> w)) {
        return 0;
    }

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        int current_weight = weights[i - 1];
        int current_value = values[i - 1];
        for (int j = 0; j <= w; j++) {
            if (current_weight <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - current_weight] + current_value);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][w] << "\n";

    return 0;
}
