// Problem: Generate All Balanced Parentheses
// Difficulty: Medium
// Topic: recursion
//
// Description: Given n pairs of parentheses, write a recursive function to generate all combinations of well-formed parentheses.
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
        generateParentheses(openCount + 1, closeCount, n, current + "(", result);
    }

    if (closeCount < openCount) {
        generateParentheses(openCount, closeCount + 1, n, current + ")", result);
    }
}

int main() {
    int n;
    if (cin >> n) {
        vector<string> result;
        generateParentheses(0, 0, n, "", result);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
