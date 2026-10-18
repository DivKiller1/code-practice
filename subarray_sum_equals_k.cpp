// Problem: Subarray Sum Equals K
// Difficulty: Medium
// Topic: hashmaps
//
// Description: Given an array of integers and an integer k, return the total number of continuous subarrays whose sum equals k using prefix sums and a hashmap.
// Example Input: 3 2
// 1 1 1
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

    unordered_map<long long, int> prefixSumFreq;
    prefixSumFreq[0] = 1;

    long long currentSum = 0;
    long long totalSubarrays = 0;

    for (int i = 0; i < n; i++) {
        currentSum += nums[i];
        long long neededSum = currentSum - k;

        if (prefixSumFreq.find(neededSum) != prefixSumFreq.end()) {
            totalSubarrays += prefixSumFreq[neededSum];
        }

        prefixSumFreq[currentSum]++;
    }

    cout << totalSubarrays << "\n";

    return 0;
}
