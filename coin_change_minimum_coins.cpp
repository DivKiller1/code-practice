// Problem: Coin Change Minimum Coins
// Difficulty: Medium
// Topic: dynamic programming
//
// Description: Given an array of coin denominations and a target amount, find the minimum number of coins needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, print -1.
// Example Input: 3 11
// 1 2 5
// Example Output: 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, amount;
    if (!(cin >> n >> amount)) {
        return 0;
    }

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    const int INF = 1e9;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] >= INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[amount] << "\n";
    }

    return 0;
}
