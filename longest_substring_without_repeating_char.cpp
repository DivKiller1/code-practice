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
    int maxLength = 0;
    vector<int> charIndex(256, -1);

    int left = 0;
    for (int right = 0; right < n; ++right) {
        unsigned char currentChar = s[right];
        if (charIndex[currentChar] >= left) {
            left = charIndex[currentChar] + 1;
        }
        charIndex[currentChar] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    if (cin >> input) {
        int result = lengthOfLongestSubstring(input);
        cout << result << "\n";
    } else {
        cout << 0 << "\n";
