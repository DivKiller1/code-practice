// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: strings
//
// Description: Given a string s, find the length of the longest substring without repeating characters.
// Example Input: abcabcbb
// Example Output: 3

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    int n = s.length();
    if (n == 0) {
        return 0;
    }

    vector<int> lastPos(256, -1);
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        unsigned char currentChar = s[end];
        if (lastPos[currentChar] >= start) {
            start = lastPos[currentChar] + 1;
        }
        lastPos[currentChar] = end;
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        int result = lengthOfLongestSubstring(s);
        cout << result << "\n";
    }

    return 0;
}
