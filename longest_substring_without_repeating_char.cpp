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

    unordered_map<char, int> last_seen;
    int max_length = 0;
    int left = 0;

    for (int right = 0; right < (int)s.length(); ++right) {
        char current_char = s[right];

        if (last_seen.find(current_char) != last_seen.end() && last_seen[current_char] >= left) {
            left = last_seen[current_char] + 1;
        }

        last_seen[current_char] = right;
        max_length = max(max_length, right - left + 1);
    }

    cout << max_length << "\n";

    return 0;
}
