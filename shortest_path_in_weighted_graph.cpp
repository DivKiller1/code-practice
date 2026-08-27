// Problem: Shortest Path in Weighted Graph
// Difficulty: Medium
// Topic: graphs
//
// Description: Given a directed graph with non-negative edge weights and a starting node, compute the shortest path distance from the start node to all other nodes.
// Example Input: 5 6 1 \n 1 2 2 \n 1 3 4 \n 2 3 1 \n 2 4 7 \n 3 5 3 \n 4 5 1
// Example Output: 0 2 3 9 6

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, start;
    if (!(cin >> n >> m >> start)) {
        return 0;
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            cout << -1 << (i == n ? "" : " ");
        } else {
            cout << dist[i] << (i == n ? "" : " ");
        }
    }
    cout << "\n";

    return 0;
}
