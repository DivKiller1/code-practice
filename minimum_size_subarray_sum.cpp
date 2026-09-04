// Problem: Minimum Size Subarray Sum
// Difficulty: Medium
// Topic: sliding window
//
// Description: Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray whose sum is greater than or equal to target. If no such subarray exists, return 0.
// Example Input: 6 7\n2 3 1 2 4 3
// Example Output: 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    if (!(cin >> n >> target)) {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int min_len = INT_MAX;
    int current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        current_sum += nums[right];

        while (current_sum >= target) {
            min_len = min(min_len, right - left + 1);
            current_sum -= nums[left];
            left++;
        }
    }

    if (min_len == INT_MAX) {
        cout << 0 << "\n";
    } else {
        cout << min_len << "\n";
    }

    return 0;
}
