// Problem: Merge Overlapping Intervals
// Difficulty: Medium
// Topic: sorting
//
// Description: Given a list of intervals, merge all overlapping intervals and print the resulting intervals in sorted order.
// Example Input: 4 1 3 2 6 8 10 15 18
// Example Output: [1, 6] [8, 10] [15, 18]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < n; i++) {
        Interval& last = merged.back();
        if (intervals[i].start <= last.end) {
            last.end = max(last.end, intervals[i].end);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    for (size_t i = 0; i < merged.size(); i++) {
        cout << "[" << merged[i].start << ", " << merged[i].end << "]"
             << (i + 1 == merged.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}
