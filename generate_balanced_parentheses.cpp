// Problem: Generate Balanced Parentheses
// Difficulty: Medium
// Topic: recursion
//
// Description: Given an integer n, generate all valid combinations of n pairs of balanced parentheses using recursion.
// Example Input: 3
// Example Output: ((())) (()()) (())() ()(()) ()()()

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParentheses(int open, int close, int n, string current, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        generateParentheses(open + 1, close, n, current + "(", result);
    }
    if (close < open) {
        generateParentheses(open, close + 1, n, current + ")", result);
    }
}

int main() {
    int n;
    if (cin >> n) {
        vector<string> result;
        generateParentheses(0, 0, n, "", result);
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i + 1 == result.size() ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
