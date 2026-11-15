// Problem: 0/1 Knapsack Problem
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given N items with specific weights and values, determine the maximum total value of items that can be packed into a knapsack of capacity W.
// Example Input: 3 50\n60 100 120\n10 20 30
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

    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    vector<int> wt(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    // dp[i][j] stores the maximum value using a subset of the first i items with max capacity j
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][w] << "\n";

    return 0;
}
