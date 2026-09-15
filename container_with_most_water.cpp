// Problem: Container With Most Water
// Difficulty: Medium
// Topic: two pointers
//
// Description: Given an array of n non-negative integers representing line heights, find two lines that together with the x-axis form a container holding the most water.
// Example Input: 9 1 8 6 2 5 4 8 3 7
// Example Output: 49

#include <bits/stdc++.h>
using namespace std;

int maxArea(const vector<int>& height) {
    int left = 0;
    int right = (int)height.size() - 1;
    int max_water = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        max_water = max(max_water, h * w);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = maxArea(height);
    cout << result << "\n";

    return 0;
}
