// Problem: Generate Binary Numbers from 1 to N
// Difficulty: Easy
// Topic: queue
//
// Description: Given an integer N, generate and print all binary representations of numbers from 1 to N sequentially using a queue.
// Example Input: 5
// Example Output: 1 10 11 100 101

#include <bits/stdc++.h>
using namespace std;

void generateBinaryNumbers(int n) {
    if (n <= 0) return;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string current = q.front();
        q.pop();

        cout << current << (i == n ? "" : " ");

        q.push(current + "0");
        q.push(current + "1");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        generateBinaryNumbers(n);
    }

    return 0;
}
