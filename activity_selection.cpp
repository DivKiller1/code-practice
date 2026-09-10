// Problem: Activity Selection
// Difficulty: Medium
// Topic: greedy
//
// Description: Given a list of activities with start and end times, find the maximum number of non-overlapping activities that can be performed by a single person.
// Example Input: 6 1 2 3 4 0 6 5 7 8 9 5 9
// Example Output: 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compareActivities(const Activity& a, const Activity& b) {
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
    int lastFinish = -1;

    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            count++;
            lastFinish = activities[i].finish;
        }
    }

    cout << count << "\n";

    return 0;
}
