// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: strings
//
// Description: Given a string s, find the length of the longest substring without repeating characters.
// Example Input: abcabcbb
// Example Output: 3

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(const string &s) {
    vector<int> last_seen(256, -1);
    int max_len = 0;
    int start = 0;
    int n = s.length();
    
    for (int end = 0; end < n; end++) {
        unsigned char ch = s[end];
        if (last_seen[ch] >= start) {
            start = last_seen[ch] + 1;
        }
        last_seen[ch] = end;
        max_len = max(max_len, end - start + 1);
    }
    
    return max_len;
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
