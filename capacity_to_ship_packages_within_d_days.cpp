// Problem: Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Topic: binary search
//
// Description: Given an array of package weights and an integer days, find the minimum weight capacity
// of a ship to transport all packages within the given number of days in the given order.
// Example Input: 6 3 \n 3 2 2 4 1 4
// Example Output: 6

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canShip(const vector<int>& weights, int days, int capacity) {
    int daysNeeded = 1;
    int currentLoad = 0;
    
    for (int w : weights) {
        if (w > capacity) {
            return false;
        }
        if (currentLoad + w > capacity) {
            daysNeeded++;
            currentLoad = w;
        } else {
            currentLoad += w;
        }
    }
    
    return daysNeeded <= days;
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
