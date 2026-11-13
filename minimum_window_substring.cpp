// Problem: Minimum Window Substring
// Difficulty: Hard
// Topic: strings
//
// Description: Given two strings s and t, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return an empty string.
// Example Input: ADOBECODEBANC ABC
// Example Output: BANC

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) {
        return "";
    }

    vector<int> t_freq(128, 0);
    for (char c : t) {
        t_freq[c]++;
    }

    vector<int> window_freq(128, 0);
    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (t_freq[i] > 0) {
            required++;
        }
    }

    int left = 0, right = 0;
    int formed = 0;
    int min_len = INT_MAX;
    int start_idx = 0;

    while (right < (int)s.length()) {
        char c = s[right];
        window_freq[c]++;

        if (t_freq[c] > 0 && window_freq[c] == t_freq[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            c = s[left];

            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }

            window_freq[c]--;
            if (t_freq[c] > 0 && window_freq[c] < t_freq[c]) {
                formed--;
            }
            left++;
        }

        right++;
    }

    return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    if (cin >> s >> t) {
        cout << minWindow(s, t) << "\n";
    }

    return 0;
}
