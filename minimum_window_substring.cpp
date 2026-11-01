// Problem: Minimum Window Substring
// Difficulty: Hard
// Topic: strings
//
// Description: Given two strings s and t, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If no such substring exists, return an empty string.
// Example Input: s = "ADOBECODEBANC", t = "ABC"
// Example Output: "BANC"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) {
        return "";
    }

    unordered_map<char, int> target_freq;
    for (char c : t) {
        target_freq[c]++;
    }

    int required_unique = target_freq.size();
    int left = 0, right = 0;
    int formed_unique = 0;

    unordered_map<char, int> window_counts;

    int min_len = INT_MAX;
    int min_left = 0;

    while (right < static_cast<int>(s.length())) {
        char current_char = s[right];
        window_counts[current_char]++;

        if (target_freq.count(current_char) && window_counts[current_char] == target_freq[current_char]) {
            formed_unique++;
        }

        while (left <= right && formed_unique == required_unique) {
            char left_char = s[left];

            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }

            window_counts[left_char]--;
            if (target_freq.count(left_char) && window_counts[left_char] < target_freq[left_char]) {
                formed_unique--;
            }

            left++;
        }

        right++;
    }

    if (min_len == INT_MAX) {
        return "";
    }

    return s.substr(min_left, min_len);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    if (cin >> s >> t) {
        string result = minWindow(s, t);
        cout << result << "\n";
    }

    return 0;
}
