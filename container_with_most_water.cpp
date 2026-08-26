// Problem: Container With Most Water
// Difficulty: Medium
// Topic: two pointers
//
// Description: Given an array of integers representing line heights, find two lines that together with the x-axis form a container that holds the maximum amount of water.
// Example Input: 9 1 8 6 2 5 4 8 3 7
// Example Output: 49

#include <bits/stdc++.h>
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
    int max_area = 0;

    while (left < right) {
        int current_height = min(height[left], height[right]);
        int width = right - left;
        int current_area = current_height * width;
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
