// Problem: Maximum Non-Overlapping Intervals
// Difficulty: Medium
// Topic: greedy
//
// Description: Given n intervals with start and end times, find the maximum number of mutually non-overlapping intervals you can select.
// Example Input: 4\n1 2\n2 3\n3 4\n1 3
// Example Output: 3

#include <iostream>
#include <vector>
#include <algorithm>

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

    int count = 1;
    int last_end = intervals[0].end;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= last_end) {
            count++;
            last_end = intervals[i].end;
        }
    }

    cout << count << "\n";

    return 0;
}
