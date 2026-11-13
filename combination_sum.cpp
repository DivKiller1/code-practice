// Problem: Combination Sum
// Difficulty: Medium
// Topic: recursion
//
// Description: Given an array of distinct positive integers and a target integer, find all unique combinations of numbers that sum up to the target using recursion. Each candidate number may be used an unlimited number of times.
// Example Input: 4 7 2 3 6 7
// Example Output: 2 2 3 7

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (index == (int)candidates.size()) {
        return;
    }

    if (candidates[index] <= target) {
        current.push_back(candidates[index]);
        findCombinations(index, target - candidates[index], candidates, current, result);
        current.pop_back();
    }

    findCombinations(index + 1, target, candidates, current, result);
}

int main() {
    int n, target;
    if (!(cin >> n >> target)) return 0;

    vector<int> candidates(n);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> current;

    findCombinations(0, target, candidates, current, result);

    for (const auto& comb : result) {
        for (size_t i = 0; i < comb.size(); i++) {
            cout << comb[i] << (i + 1 == comb.size() ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
