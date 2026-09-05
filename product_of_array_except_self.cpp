// Problem: Product of Array Except Self
// Difficulty: Medium
// Topic: arrays
//
// Description: Given an array of integers, construct a new array where each element at index i is the product of all the numbers in the original array except the one at index i, without using division.
// Example Input: 4 1 2 3 4
// Example Output: 24 12 8 6

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result(n, 1);

    // Calculate prefix products for each element
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Calculate suffix products and multiply with existing prefix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    // Output the resulting array
    for (int i = 0; i < n; i++) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
