// Problem: Product of Array Except Self
// Difficulty: Medium
// Topic: arrays
//
// Description: Given an array of integers nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i] without using division.
// Example Input: 4 1 2 3 4
// Example Output: 24 12 8 6

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> result(n, 1);

    long long prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    long long suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
