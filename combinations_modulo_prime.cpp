// Problem: Combinations Modulo Prime
// Difficulty: Medium
// Topic: math
//
// Description: Calculate n choose r modulo 10^9 + 7 using factorials and modular multiplicative inverse.
// Example Input: 5 2
// Example Output: 10

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;

    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long num = fact[n];
    long long den = (fact[r] * fact[n - r]) % MOD;

    return (num * modInverse(den)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    if (cin >> n >> r) {
        cout << nCr(n, r) << "\n";
    }

    return 0;
}
