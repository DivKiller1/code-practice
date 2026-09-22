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
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastSeen;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < static_cast<int>(s.length()); end++) {
        char currentChar = s[end];
        
        if (lastSeen.find(currentChar) != lastSeen.end() && lastSeen[currentChar] >= start) {
            start = lastSeen[currentChar] + 1;
        }

        lastSeen[currentChar] = end;
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        cout << lengthOfLongestSubstring(s) << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
