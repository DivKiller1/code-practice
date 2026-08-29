// Problem: Koko Eating Bananas
// Difficulty: Medium
// Topic: binary search
//
// Description: Given an array of banana piles and an integer h representing available hours,
// determine the minimum eating speed k (bananas per hour) to finish all piles within h hours.
// Example Input: 4 8
// 3 6 7 11
// Example Output: 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFinish(const vector<int>& piles, int h, int k) {
    long long hoursSpent = 0;
    for (int pile : piles) {
        hoursSpent += (pile + k - 1) / k;
    }
    return hoursSpent <= h;
}

int minEatingSpeed(const vector<int>& piles, int h) {
    int low = 1;
    int high = 0;
    for (int pile : piles) {
        high = max(high, pile);
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canFinish(piles, h, mid)) {
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

    int n, h;
    if (!(cin >> n >> h)) return 0;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int min_speed = minEatingSpeed(piles, h);
    cout << min_speed << "\n";

    return 0;
}
