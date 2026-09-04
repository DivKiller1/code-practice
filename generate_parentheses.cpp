// Problem: Generate Parentheses
// Difficulty: Medium
// Topic: recursion
//
// Description: Given an integer N representing the number of pairs of parentheses, generate all combinations of well-formed parentheses using recursion.
// Example Input: 3
// Example Output: ((())) (()()) (())() ()(()) ()()()

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParentheses(int openCount, int closeCount, int n, string current, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (openCount < n) {
        generateParentheses(openCount + 1, closeCount, n, current + '(', result);
    }

    if (closeCount < openCount) {
        generateParentheses(openCount, closeCount + 1, n, current + ')', result);
    }
}

int main() {
    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<string> result;
    generateParentheses(0, 0, n, "", result);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 == result.size() ? "" : " ");
    }
    cout << endl;

    return 0;
}
