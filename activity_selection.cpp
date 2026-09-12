// Problem: Activity Selection
// Difficulty: Easy
// Topic: greedy
//
// Description: Given N activities with their start and finish times, find the maximum number of activities that can be performed by a single person without any overlapping.
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

int selectMaxActivities(vector<Activity>& activities) {
    if (activities.empty()) return 0;

    sort(activities.begin(), activities.end(), compareActivities);

    int count = 1;
    int lastFinish = activities[0].finish;

    for (size_t i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            count++;
            lastFinish = activities[i].finish;
        }
    }

    return count;
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

    int maxAct = selectMaxActivities(activities);
    cout << maxAct << "\n";

    return 0;
}
