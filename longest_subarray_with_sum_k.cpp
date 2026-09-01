// Problem: Longest Subarray with Sum K
// Difficulty: Medium
// Topic: hashmaps
//
// Description: Given an array of N integers and a target sum K, find the length of the longest contiguous subarray whose sum equals K.
// Example Input: 6 15\n10 5 2 7 1 9
// Example Output: 4

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    unordered_map<long long, int> prefix_map;
    long long current_sum = 0;
    int max_length = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += arr[i];

        if (current_sum == k) {
            max_length = i + 1;
        }

        if (prefix_map.find(current_sum - k) != prefix_map.end()) {
            max_length = max(max_length, i - prefix_map[current_sum - k]);
        }

        if (prefix_map.find(current_sum) == prefix_map.end()) {
            prefix_map[current_sum] = i;
        }
    }

    cout << max_length << "\n";

    return 0;
}
