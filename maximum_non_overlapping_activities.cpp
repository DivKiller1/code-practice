// Problem: Maximum Non-Overlapping Activities
// Difficulty: Medium
// Topic: greedy
//
// Description: Given N activities with start and end times, select the maximum number of activities that can be performed by a single person without overlapping.
// Example Input: 6\n1 2\n3 4\n0 6\n5 7\n8 9\n5 9
// Example Output: 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int end;
};

// Greedy strategy: Sort activities by their end times in ascending order.
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
    if (!(cin >> n) || n <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end;
    }

    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), compareActivities);

    int count = 0;
    int last_end_time = -1;

    // Greedily pick the first activity that starts after or at the end of the previously chosen activity
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= last_end_time) {
            count++;
            last_end_time = activities[i].end;
        }
    }

    cout << count << "\n";

    return 0;
}
