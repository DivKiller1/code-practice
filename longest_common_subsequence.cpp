// Problem: Longest Common Subsequence
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given two strings text1 and text2, return the length of their longest common subsequence.
// Example Input: abcde ace
// Example Output: 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text1, text2;
    if (!(cin >> text1 >> text2)) {
        return 0;
    }

    int m = text1.length();
    int n = text2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[m][n] << "\n";

    return 0;
}
