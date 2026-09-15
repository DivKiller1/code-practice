// Problem: Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Topic: binary search
//
// Description: Given an array of package weights and an integer days, return the least weight capacity of a ship to ship all packages within days.
// Example Input: 10 5 1 2 3 4 5 6 7 8 9 10
// Example Output: 15

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canShip(const vector<int>& weights, int days, int capacity) {
    int current_days = 1;
    int current_load = 0;
    for (int weight : weights) {
        if (current_load + weight > capacity) {
            current_days++;
            current_load = weight;
        } else {
            current_load += weight;
        }
    }
    return current_days <= days;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, days;
    if (!(cin >> n >> days)) {
        return 0;
    }

    vector<int> weights(n);
    int max_weight = 0;
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        max_weight = max(max_weight, weights[i]);
        total_weight += weights[i];
    }

    int low = max_weight;
    int high = total_weight;
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canShip(weights, days, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}
