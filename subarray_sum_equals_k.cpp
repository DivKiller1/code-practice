// Problem: Subarray Sum Equals K
// Difficulty: Medium
// Topic: hashmaps
//
// Description: Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// Example Input: 5 2\n1 1 1 1 1
// Example Output: 4

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> prefix_counts;
    prefix_counts[0] = 1;

    int current_sum =
