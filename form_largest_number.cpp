// Problem: Form Largest Number
// Difficulty: Medium
// Topic: sorting
//
// Description: Given an array of non-negative integers, arrange them such that they form the largest possible number when concatenated.
// Example Input: 5 \n 10 2 9 39 34
// Example Output: 93934210

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator function to determine string ordering
bool compareStrings(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Sort the numbers using custom string concatenation rule
    sort(numbers.begin(), numbers.end(), compareStrings);

    // Handle edge case where all numbers are zero
    if (numbers[0] == "0") {
        cout << "0\n";
        return 0;
    }

    // Construct the resulting largest number string
    string largestNumber = "";
    for (int i = 0; i < n; i++) {
        largestNumber += numbers[i];
    }

    cout << largestNumber << "\n";

    return 0;
}
