// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: sliding window
//
// Description: Given a string s, find the length of the longest substring without repeating characters.
// Example Input: abcabcbb
// Example Output: 3

#include <iostream>
#include <string>
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
    unordered_map<char, int> char_index;
    int max_length = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        char current_char = s[right];
        if (char_index.find(current_char) != char_index.end()) {
            left = max(left, char_index[current_char] + 1);
        }
        char_index[current_char] = right;
        int current_window_size = right - left + 1;
        max_length = max(max_length, current_window_size);
    }

    cout << max_length << "\n";
    return 0;
}
