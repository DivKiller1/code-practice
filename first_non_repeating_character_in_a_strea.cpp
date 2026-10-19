// Problem: First Non-Repeating Character in a Stream
// Difficulty: Medium
// Topic: queue
//
// Description: Given a string representing a stream of characters, find the first non-repeating character after processing each character. Output '#' if no non-repeating character exists at that point.
// Example Input: aabc
// Example Output: a#bb

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string stream;
    if (!(cin >> stream)) {
        return 0;
    }

    queue<char> q;
    vector<int> charCount(26, 0);
    string result = "";

    for (char c : stream) {
        q.push(c);
        charCount[c - 'a']++;

        while (!q.empty() && charCount[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            result += q.front();
        } else {
            result += '#';
        }
    }

    cout << result << "\n";

    return 0;
}
