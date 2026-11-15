// Problem: Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Topic: binary search
//
// Description: Find the minimum ship weight capacity needed to ship all packages on a conveyor belt within a given number of days.
// Example Input: 10 5\n1 2 3 4 5 6 7 8 9 10
// Example Output: 15

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canShip(const vector<int>& weights, int days, int capacity) {
    int current_weight = 0;
    int required_days = 1;
    for (int w : weights) {
        if (w > capacity) {
            return false;
        }
        if (current_weight + w > capacity) {
            required_days++;
            current_weight = w;
        } else {
            current_weight += w;
        }
    }
    return required_days <= days;
}

int shipWithinDays(const vector<int>& weights, int days) {
    int max_weight = 0;
    int sum_weight = 0;
    for (int w : weights) {
        max_weight = max(max_weight, w);
        sum_weight += w;
    }

    int low = max_weight;
    int high = sum_weight;
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

    cout << shipWithinDays(weights, days) << "\n";

    return 0;
}
