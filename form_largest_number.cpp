// Problem: Form Largest Number
// Difficulty: Medium
// Topic: sorting
//
// Description: Given a list of non-negative integers, arrange them such that they form the largest possible number when concatenated.
// Example Input: 5 3 30 34 5 9
// Example Output: 9534330

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compareNumStrings(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), compareNumStrings);

    if (!nums.empty() && nums[0] == "0") {
        cout << "0" << "\n";
        return 0;
    }

    string largestNumber = "";
    for (int i = 0; i < n; i++) {
        largestNumber += nums[i];
    }

    cout << largestNumber << "\n";

    return 0;
}
