// Problem: Activity Selection Problem
// Difficulty: Medium
// Topic: greedy
//
// Description: Given N activities with their start and end times, select the maximum number of non-overlapping activities that can be performed by a single person.
// Example Input: N = 4, Intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
// Example Output: 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int end;
};

bool compareActivities(const Activity& a, const Activity& b) {
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

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end;
    }

    sort(activities.begin(), activities.end(), compareActivities);

    int count = 0;
    int last_end_time = -1;

    for (int
