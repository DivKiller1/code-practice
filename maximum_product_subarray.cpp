// Problem: Maximum Product Subarray
// Difficulty: Medium
// Topic: arrays
//
// Description: Given an integer array nums, find a contiguous non-empty subarray that has the largest product, and return the product.
// Example Input: 4\n2 3 -2 4
// Example Output: 6

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

    long long max_product = nums[0];
    long long current_max = nums[0];
    long long current_min = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) {
            swap(current_max, current_min);
        }

        current_max = max(nums[i], current_max * nums[i]);
        current_min = min(nums[i], current_min * nums[i]);

        max_product = max(max_product, current_max);
    }

    cout << max_product << "\n";

    return 0;
}
