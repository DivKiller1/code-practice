// Problem: Edit Distance
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. Allowed operations are insertion, deletion, or substitution of a character.
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
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int deleteOp = dp[i - 1][j];
                int insertOp = dp[i][j - 1];
                int replaceOp = dp[i - 1][j - 1];
                dp[i][j] = 1 + min({deleteOp, insertOp, replaceOp});
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
        int result = minDistance(word1, word2);
        cout << result << "\n";
    }

    return 0;
}
