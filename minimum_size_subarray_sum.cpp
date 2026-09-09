// Problem: Minimum Size Subarray Sum
// Difficulty: Medium
// Topic: sliding window
//
// Description: Given an array of positive integers nums and a positive integer target, find the minimal length of a contiguous subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
// Example Input: 7 6 2 3 1 2 4 3
// Example Output: 2

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int target, n;
    if (!(cin >> target >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int left = 0;
    int current_sum = 0;
    int min_length = INT_MAX;

    for (int right = 0; right < n; right++) {
        current_sum += nums[right];

        while (current_sum >= target) {
            min_length = min(min_length, right - left + 1);
            current_sum -= nums[left];
            left++;
        }
    }

    if (min_length == INT_MAX) {
        cout << 0 << endl;
    } else {
        cout << min_length << endl;
    }

    return 0;
}
