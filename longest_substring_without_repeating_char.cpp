// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: strings
//
// Description: Given a string s, find the length of the longest substring
// without repeating characters.
// Example Input: abcabcbb
// Example Output: 3

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const string& s) {
    vector<int> last_index(256, -1);
    int max_len = 0;
    int start = 0;

    for (int i = 0; i < (int)s.length(); ++i) {
        unsigned char current_char = s[i];
        if (last_index[current_char] >= start) {
            start = last_index[current_char] + 1;
        }
        last_index[current_char] = i;
        max_len = max(max_len, i - start + 1);
    }

    return max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        int result = solve(s);
        cout << result << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
