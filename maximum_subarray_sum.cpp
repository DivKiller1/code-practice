// Problem: Maximum Subarray Sum
// Difficulty: Medium
// Topic: arrays
//
// Description: Given an array of integers, find the contiguous subarray with the largest sum and print the maximum sum.
// Example Input: 9 -2 1 -3 4 -1 2 1 -5 4
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

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long max_so_far = nums[0];
    long long max_ending_here = nums[0];

    for (int i = 1; i < n; i++) {
        max_ending_here = max((long long)nums[i], max_ending_here + nums[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    cout << max_so_far << "\n";

    return 0;
}
