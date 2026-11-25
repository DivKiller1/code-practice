// Problem: Container With Most Water
// Difficulty: Medium
// Topic: two pointers
//
// Description: Given an array of non-negative integers representing vertical line heights, find two lines that together with the x-axis form a container containing the most water. Return the maximum area of water that can be stored.
// Example Input: 9 1 8 6 2 5 4 8 3 7
// Example Output: 49

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int left = 0;
    int right = n - 1;
    long long max_area = 0;

    while (left < right) {
        long long current_height = min(height[left], height[right]);
        long long current_width = right - left;
        long long current_area = current_height * current_width;

        max_area = max(max_area, current_area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    cout << max_area << "\n";

    return 0;
}
