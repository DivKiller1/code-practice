// Problem: Subarray Sum Equals K
// Difficulty: Medium
// Topic: hashmaps
//
// Description: Given an array of integers and an integer k, return the total number of continuous subarrays whose sum equals to k.
// Example Input: 5 2\n1 1 1 -1 2
// Example Output: 4

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

    unordered_map<long long, int> prefix_sum_counts;
    prefix_sum_counts[0] = 1;

    long long current_sum = 0;
    long long total_subarrays = 0;

    for (int i = 0; i < n; i++) {
        current_sum += nums[i];
        
        long long target = current_sum - k;
        if (prefix_sum_counts.find(target) != prefix_sum_counts.end()) {
            total_subarrays += prefix_sum_counts[target];
        }

        prefix_sum_counts[current_sum]++;
    }

    cout << total_subarrays << endl;

    return 0;
}
