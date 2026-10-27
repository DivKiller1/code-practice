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
    vector<int> last_seen(256, -1);
    int max_len = 0;
    int start = 0;

    for (int i = 0; i < (int)s.length(); ++i) {
        unsigned char c = s[i];
        if (last_seen[c] >= start) {
            start = last_seen[c] + 1;
        }
        last_seen[c] = i;
        max_len = max(max_len, i - start + 1);
    }

    return max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (getline(cin, s)) {
        if (!s.empty() && s.back() == '\r') {
            s.pop_back();
        }
        cout << lengthOfLongestSubstring(s) << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
