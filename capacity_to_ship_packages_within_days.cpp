// Problem: Capacity To Ship Packages Within Days
// Difficulty: Medium
// Topic: binary search
//
// Description: Given an array of package weights and a maximum number of days, find the minimum boat capacity needed to ship all packages in order within the given days.
// Example Input: 5 3
// 1 2 3 4 5
// Example Output: 6

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canShip(const vector<int>& weights, int days, int capacity) {
    int current_days = 1;
    int current_weight = 0;

    for (int w : weights) {
        if (current_weight + w > capacity) {
            current_days++;
            current_weight = w;
        } else {
            current_weight += w;
        }
    }

    return current_days <= days;
}

int shipWithinDays(const vector<int>& weights, int days) {
    int low = 0;
    int high = 0;

    for (int w : weights) {
        low = max(low, w);
        high += w;
    }

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

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, days;
    if (!(cin >> n >> days)) return 0;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int minCapacity = shipWithinDays(weights, days);
    cout << minCapacity << "\n";

    return 0;
}
