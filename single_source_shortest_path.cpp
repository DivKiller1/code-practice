// Problem: Single Source Shortest Path
// Difficulty: Medium
// Topic: graphs
//
// Description: Given a weighted directed graph with non-negative edge weights and a starting vertex, calculate the shortest distance from the source vertex to all other vertices.
// Example Input: 5 6 1\n1 2 2\n1 3 4\n2 3 1\n2 4 7\n3 5 3\n5 4 2
// Example Output: 0 2 3 8 6

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, src;
    if (!(cin >> n >> m >> src)) {
        return 0;
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        long long d = top.first;
        int u = top.second;

        if (d > dist[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1;
        } else {
            cout << dist[i];
        }
        if (i < n) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}
