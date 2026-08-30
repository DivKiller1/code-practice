// Problem: Generate Balanced Parentheses
// Difficulty: Medium
// Topic: recursion
//
// Description: Given n pairs of parentheses, write a recursive function to generate all combinations of well-formed parentheses in lexicographical order.
// Example Input: 3
// Example Output: ((())) (()()) (())() ()(()) ()()()

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParentheses(int openCount, int closeCount, int totalPairs, string current, vector<string>& result) {
    if (current.length() == 2 * totalPairs) {
        result.push_back(current);
        return;
    }

    if (openCount < totalPairs) {
        generateParentheses(openCount + 1, closeCount, totalPairs, current + "(", result);
    }

    if (closeCount < openCount) {
        generateParentheses(openCount, closeCount + 1, totalPairs, current + ")", result);
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
