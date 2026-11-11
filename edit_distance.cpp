// Problem: Edit Distance
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given two strings word1 and word2, return the minimum number of operations (insert, delete, or replace a character) required to convert word1 into word2.
// Example Input: horse ros
// Example Output: 3

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(const string& word1, const string& word2) {
    int m = word1.length();
    int n = word2.length();

    // dp[i][j] stores the edit distance between word1[0...i-1] and word2[0...j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base case: converting word1[0...i-1] to empty string requires i deletions
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    // Base case: converting empty string to word2[0...j-1] requires j insertions
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int delete_op = dp[i - 1][j];
                int insert_op = dp[i][j - 1];
                int replace_op = dp[i - 1][j - 1];
                dp[i][j] = 1 + min({delete_op, insert_op, replace_op});
            }
        }
    }

    return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word1, word2;
    if (cin >> word1 >> word2) {
        cout << minDistance(word1, word2) << "\n";
    }

    return 0;
}
