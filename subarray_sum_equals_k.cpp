// Problem: Subarray Sum Equals K
// Difficulty: Medium
// Topic: hashmaps
//
// Description: Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// Example Input: 3 2\n1 1 1
// Example Output: 2

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(const vector<int>& nums, int k) {
    unordered_map<int, int> prefixCounts;
    prefixCounts[0] = 1;
    
    int currentSum = 0;
    int totalSubarrays = 0;
    
    for (int num : nums) {
        currentSum += num;
        int neededSum = currentSum - k;
        
        if (prefixCounts.find(neededSum) != prefixCounts.end()) {
            totalSubarrays += prefixCounts[neededSum];
        }
        
        prefixCounts[currentSum]++;
    }
    
    return totalSubarrays;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    if (!(cin >> n >> k)) {
        return 0;
    }
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int result = subarraySum(nums, k);
    cout << result << "\n";
    
    return 0;
}
