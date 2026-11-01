// Problem: First Non-Repeating Character in a Stream
// Difficulty: Medium
// Topic: queue
//
// Description: Given a string representing a stream of lowercase characters, find the first non-repeating character after processing each input character. Print '#' if no non-repeating character exists at that point.
// Example Input: aabccxb
// Example Output: a#bbbbx

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string stream;
    if (!(cin >> stream)) {
        return 0;
    }

    vector<int> freq(26, 0);
    queue<char> q;
    string result = "";

    for (char ch : stream) {
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            result += '#';
        } else {
            result += q.front();
        }
    }

    cout << result << "\n";

    return 0;
}
