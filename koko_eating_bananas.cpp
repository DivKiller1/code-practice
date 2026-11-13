// Problem: Koko Eating Bananas
// Difficulty: Medium
// Topic: binary search
//
// Description: Given an array of banana pile sizes and an integer h representing the available hours, find the minimum eating speed k (bananas per hour) such that Koko can eat all bananas within h hours.
// Example Input: 4 8\n3 6 7 11
// Example Output: 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFinish(const vector<int>& piles, int h, int speed) {
    long long hours_needed = 0;
    for (int pile : piles) {
        hours_needed += (pile + speed - 1) / speed;
    }
    return hours_needed <= h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    if (!(cin >> n >> h)) {
        return 0;
    }

    vector<int> piles(n);
    int max_pile = 0;
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        max_pile = max(max_pile, piles[i]);
    }

    int low = 1;
    int high = max_pile;
    int ans = max_pile;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canFinish(piles, h, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
