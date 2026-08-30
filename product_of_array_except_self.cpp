// Problem: Product of Array Except Self
// Difficulty: Medium
// Topic: arrays
//
// Description: Given an array of integers, return an array where each element at index i is equal to the product of all elements in the original array except the element at index i, calculated without using division.
// Example Input: 4 1 2 3 4
// Example Output: 24 12 8 6

#include <iostream>
#include <vector>

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

    vector<int> result(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
