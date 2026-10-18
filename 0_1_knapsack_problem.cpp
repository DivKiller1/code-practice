// Problem: 0/1 Knapsack Problem
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given n items with specified weights and values, determine the maximum total value that can be placed in a knapsack of capacity W.
// Example Input: 3 50\n60 100 120\n10 20 30
// Example Output: 220

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W;
    if (!(cin >> n >> W)) return 0;

    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    vector<int> wt(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    cout << dp[W] << "\n";

    return 0;
}
