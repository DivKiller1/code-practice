// Problem: First Non-Repeating Character in a Stream
// Difficulty: Medium
// Topic: queue
//
// Description: Given a string representing a stream of characters, find the first non-repeating character after each insertion. Output '#' if no non-repeating character exists.
// Example Input: aabccxb
// Example Output: a # b b b b x

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string stream;
    if (!(cin >> stream)) {
        return 0;
    }

    unordered_map<char, int> freq;
    queue<char> q;
    vector<char> result;

    for (char ch : stream) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            result.push_back('#');
        } else {
            result.push_back(q.front());
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i + 1 == result.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}
