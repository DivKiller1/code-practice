// Problem: Subarray Sum Equals K
// Difficulty: Medium
// Topic: hashmaps
//
// Description: Given an array of integers nums and an integer target k, return the total number of continuous subarrays whose sum equals to k.
// Example Input: n = 3, k = 3, nums = [1, 2, 3]
// Example Output: 2

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<long long, int> prefix_sum_freq;
    prefix_sum_freq[0] = 1;

    long long current_sum = 0;
    long long total_subarrays = 0;

    for (int i = 0; i < n; i++) {
        current_sum += nums[i];
        long long needed_prefix = current_sum - k;

        if (prefix_sum_freq.find(needed_prefix) != prefix_sum_freq.end()) {
            total_subarrays += prefix_sum_freq[needed_prefix];
        }

        prefix_sum_freq[current_sum]++;
    }

    cout << total_subarrays << "\n";

    return 0;
}
