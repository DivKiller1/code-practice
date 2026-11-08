// Problem: Rotting Oranges
// Difficulty: Medium
// Topic: queue
//
// Description: Given an m x n grid representing a grid of oranges where 0 is empty, 1 is fresh, and 2 is rotten.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten. Return the minimum minutes until no cell has a fresh orange, or -1 if impossible.
// Example Input: 3 3 2 1 1 1 1 0 0 1 1
// Example Output: 4

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> grid(m, vector<int>(n));
    queue<pair<int, int>> q;
    int freshCount = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int minutes = 0;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty() && freshCount > 0) {
        int sz = q.size();
        minutes++;
        for (int i = 0; i < sz; ++i) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dirs[d][0];
                int nc = c + dirs[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    freshCount--;
                    q.push({nr, nc});
                }
            }
        }
    }

    if (freshCount > 0) {
        cout << -1 << "\n";
    } else {
        cout << minutes << "\n";
    }

    return 0;
}
