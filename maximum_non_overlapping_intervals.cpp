// Problem: Maximum Non-Overlapping Intervals
// Difficulty: Medium
// Topic: greedy
//
// Description: Given a list of intervals with start and end times, find the maximum number of mutually non-overlapping intervals that can be selected.
// Example Input: n = 4, intervals = [[1, 3], [2, 4], [3, 5], [0, 6]]
// Example Output: 2

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
    if (!(cin >> n) || n <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 0;
    int lastEnd = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (intervals[i].start >= lastEnd) {
            count++;
            lastEnd = intervals[i].end;
        }
    }

    cout << count << "\n";

    return 0;
}
