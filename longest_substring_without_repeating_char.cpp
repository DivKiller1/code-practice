// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: sliding window
//
// Description: Given a string s, find the length of the longest substring without repeating characters.
// Example Input: abcabcbb
// Example Output: 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> last_pos(256, -1);
    int max_len = 0;
    int left = 0;

    for (int right = 0; right < (int)s.length(); right++) {
        unsigned char current_char = s[right];
        
        if (last_pos[current_char] >= left) {
            left = last_pos[current_char] + 1;
        }
        
        last_pos[current_char] = right;
        int current_window_size = right - left + 1;
        
        if (current_window_size > max_len) {
            max_len = current_window_size;
        }
    }

    cout << max_len << "\n";
    return 0;
}
