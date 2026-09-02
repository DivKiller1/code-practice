// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: sliding window
//
// Description: Given a string s, find the length of the longest substring without repeating characters.
// Example Input: abcabcbb
// Example Output: 3

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) {
        cout << 0 << "\n";
        return 0;
    }

    int n = s.length();
    unordered_map<char, int> lastPos;
    int maxLen = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < n; ++windowEnd) {
        char currentChar = s[windowEnd];

        if (lastPos.find(currentChar) != lastPos.end() && lastPos[currentChar] >= windowStart) {
            windowStart = lastPos[currentChar] + 1;
        }

        lastPos[currentChar] = windowEnd;
        int currentLen = windowEnd - windowStart + 1;
        maxLen = max(maxLen, currentLen);
    }

    cout << maxLen << "\n";

    return 0;
}
