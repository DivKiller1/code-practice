// Problem: Number of Pairs with Given GCD and LCM
// Difficulty: Medium
// Topic: math
//
// Description: Given two positive integers g and l, find the number of ordered pairs (a, b) such that gcd(a, b) = g and lcm(a, b) = l.
// Example Input: 2 12
// Example Output: 4

#include <iostream>
#include <numeric>

using namespace std;

// Function to count distinct prime factors of a number
long long countDistinctPrimeFactors(long long n) {
    long long count = 0;
    if (n % 2 == 0) {
        count++;
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            count++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long g, l;
    if (!(cin >> g >> l)) {
        return 0;
    }

    // LCM must be divisible by GCD
    if (l % g != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long k = l / g;
    long long prime_factors_count = countDistinctPrimeFactors(k);

    // Number of valid ordered pairs is 2^p, where p is the count of distinct prime factors of (l / g)
    long long ans = 1LL << prime_factors_count;

    cout << ans << "\n";

    return 0;
}
