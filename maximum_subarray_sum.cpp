// Problem: Maximum Subarray Sum
// Difficulty: Medium
// Topic: arrays
//
// Description: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// Example Input: 9\n-2 1 -3 4 -1 2 1 -5 4
// Example Output: 6

#include <iostream>
#include <vector>
#include <algorithm>

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

    long long max_so_far = nums[0];
    long long current_max = nums[0];

    for (int i = 1; i < n; i++) {
        current_max = max(nums[i], current_max + nums[i]);
        max_so_far = max(max_so_far, current_max);
    }

    cout << max_so_far << "\n";

    return 0;
}
