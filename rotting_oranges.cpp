// Problem: Rotting Oranges
// Difficulty: Medium
// Topic: queue
//
// Description: Given a grid of fresh and rotten oranges, return the minimum time needed for all fresh oranges to become rotten using multi-source BFS with a queue.
// Example Input: 3 3 2 1 1 1 1 0 0 1 1
// Example Output: 4

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    if (!(cin >> rows >> cols)) {
        return 0;
    }

    vector<vector<int>> grid(rows, vector<int>(cols));
    queue<pair<int, int>> q;
    int freshCount = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 2) {
                q.push({r, c});
            } else if (grid[r][c] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int minutes = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty() && freshCount > 0) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            pair<int, int> current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    freshCount--;
                    q.push({nr, nc});
                }
            }
        }
        minutes++;
    }

    if (freshCount == 0) {
        cout << minutes << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
