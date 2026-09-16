// Problem: Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Topic: binary search
//
// Description: Given an array of package weights and a number of days, find the minimum weight capacity of a ship such that all packages can be shipped within the given days in order.
// Example Input: 6 3\n1 2 3 4 5 6
// Example Output: 9

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canShip(const vector<int>& weights, int days, int capacity) {
    int current_weight = 0;
    int needed_days = 1;
    for (int w : weights) {
        if (current_weight + w > capacity) {
            needed_days++;
            current_weight = w;
        } else {
            current_weight += w;
        }
    }
    return needed_days <= days;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, days;
    if (!(cin >> n >> days)) return 0;

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
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canShip(weights, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
