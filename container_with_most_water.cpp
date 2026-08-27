// Problem: Container With Most Water
// Difficulty: Medium
// Topic: two pointers
//
// Description: Given an array of n non-negative integers representing line heights, find two lines that together with the x-axis form a container holding the maximum amount of water.
// Example Input: 9\n1 8 6 2 5 4 8 3 7
// Example Output: 49

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int left = 0;
    int right = n - 1;
    int maxArea = 0;

    while (left < right) {
        int currentWidth = right - left;
        int currentHeight = min(height[left], height[right]);
        int currentArea = currentWidth * currentHeight;
        maxArea = max(maxArea, currentArea);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    cout << maxArea << "\n";

    return 0;
}
