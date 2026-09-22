// Problem: Shortest Path in Weighted Graph
// Difficulty: Medium
// Topic: graphs
//
// Description: Given a directed graph with n vertices, m edges, and non-negative edge weights, compute the shortest distance from a starting vertex to all vertices using Dijkstra's algorithm.
// Example Input: 4 5 1 \n 1 2 4 \n 1 3 2 \n 2 3 1 \n 2 4 5 \n 3 4 8
// Example Output: 0 4 2 9

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, src;
    if (!(cin >> n >> m >> src)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << (i == n ? "" : " ");
        } else {
            cout << dist[i] << (i == n ? "" : " ");
        }
    }
    cout << "\n";

    return 0;
}
