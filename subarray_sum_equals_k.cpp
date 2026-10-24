// Problem: Subarray Sum Equals K
// Difficulty: Medium
// Topic: hashmaps
//
// Description: Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// Example Input: 4 3
// 1 2 3 -3
// Example Output: 3

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

    unordered_map<long long, int> prefix_counts;
    prefix_counts[0] = 1;

    long long current_sum = 0;
    long long total_subarrays = 0;

    for (int i = 0; i < n; i++) {
        current_sum += nums[i];
        long long target = current_sum - k;

        if (prefix_counts.find(target) != prefix_counts.end()) {
            total_subarrays += prefix_counts[target];
        }

        prefix_counts[current_sum]++;
    }

    cout << total_subarrays << "\n";

    return 0;
}
