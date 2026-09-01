// Problem: Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Topic: binary search
//
// Description: Find the minimum ship weight capacity that allows shipping all packages within D days in the given order.
// Example Input: 10 5
// 1 2 3 4 5 6 7 8 9 10
// Example Output: 15

#include <bits/stdc++.h>
using namespace std;

bool canShip(const vector<int>& weights, int days, int capacity) {
    int requiredDays = 1;
    int currentWeight = 0;
    for (int w : weights) {
        if (currentWeight + w > capacity) {
            requiredDays++;
            currentWeight = w;
        } else {
            currentWeight += w;
        }
    }
    return requiredDays <= days;
}

int shipWithinDays(const vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
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
    return ans;
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
