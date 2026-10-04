// Problem: Activity Selection
// Difficulty: Medium
// Topic: greedy
//
// Description: Given N activities with their start and finish times, find the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Example Input: 4\n1 3\n2 4\n3 5\n0 6
// Example Output: 2

#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compareActivities(const Activity &a, const Activity &b) {
    if (a.finish != b.finish) {
        return a.finish < b.finish;
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
        cin >> activities[i].start >> activities[i].finish;
    }

    sort(activities.begin(), activities.end(), compareActivities);

    int count = 0;
    int lastFinishTime = -1;

    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastFinishTime) {
            count++;
            lastFinishTime = activities[i].finish;
        }
    }

    cout << count << "\n";

    return 0;
}
