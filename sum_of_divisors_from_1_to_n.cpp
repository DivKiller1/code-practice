// Problem: Sum of Divisors from 1 to N
// Difficulty: Medium
// Topic: math
//
// Description: Given an integer N, compute the sum of all divisors of all numbers from 1 to N modulo 10^9 + 7.
// Example Input: 5
// Example Output: 21

#include <iostream>

using namespace std;

static const long long MOD = 1000000007;
static const long long INV2 = 500000004; // Modular inverse of 2 modulo 10^9 + 7

// Function to compute the sum of integers from l to r inclusive modulo MOD
long long sum_range(long long l, long long r) {
    long long count = (r - l + 1) % MOD;
    long long sum_lr = (l + r) % MOD;
    long long total = (count * sum_lr) % MOD;
    return (total * INV2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) {
        return 0;
    }

    long long total_sum = 0;
    long long l = 1;

    // Use square root decomposition for n / l
    while (l <= n) {
        long long k = n / l;
        long long r = n / k;

        long long range_sum = sum_range(l, r);
        long long term = (range_sum * (k % MOD)) % MOD;
        total_sum = (total_sum + term) % MOD;

        l = r + 1;
    }

    cout << total_sum << "\n";

    return 0;
}
