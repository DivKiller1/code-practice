// Problem: Generate Parentheses
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

void generateParenthesisRecursive(int openCount, int closeCount, int n, string currentStr, vector<string>& result) {
    if (currentStr.length() == 2 * n) {
        result.push_back(currentStr);
        return;
    }

    if (openCount < n) {
        generateParenthesisRecursive(openCount + 1, closeCount, n, currentStr + "(", result);
    }
    if (closeCount < openCount) {
        generateParenthesisRecursive(openCount, closeCount + 1, n, currentStr + ")", result);
    }
}

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<string> result;
    generateParenthesisRecursive(0, 0, n, "", result);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 == result.size() ? "" : " ");
    }
    cout << endl;

    return 0;
}
