// Problem: Maximum Non-Overlapping Intervals
// Difficulty: Medium
// Topic: greedy
//
// Description: Given a set of N intervals with start and end times, find the maximum number of intervals that can be selected such that no two selected intervals overlap.
// Example Input: 4 \n 1 3 \n 2 4 \n 3 6 \n 5 7
// Example Output: 3

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    sort(intervals.begin(), intervals
