// Problem: Subarray Sum Equals K
// Difficulty: Medium
// Topic: hashmaps
//
// Description: Given an array of integers and an integer k, return the total number of continuous subarrays whose sum equals to k using a hashmap.
// Example Input: 3 2 \n 1 1 1
// Example Output: 2

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarraysWithSumK(const vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCounts;
    prefixSumCounts[0] = 1;

    int currentSum = 0;
    int count = 0;

    for (int num : nums) {
        currentSum += num;
        int neededSum = currentSum - k;

        if (prefixSumCounts.find(neededSum) != prefixSumCounts.end()) {
            count += prefixSumCounts[neededSum];
        }

        prefixSumCounts[currentSum]++;
    }

    return count;
}

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

    int result = countSubarraysWithSumK(nums, k);
    cout << result << "\n";

    return 0;
}
