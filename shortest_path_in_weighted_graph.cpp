// Problem: Shortest Path in Weighted Graph
// Difficulty: Medium
// Topic: graphs
//
// Description: Given a directed graph with N vertices and M edges with non-negative weights, find the shortest path distance from vertex S to vertex T using Dijkstra's algorithm.
// Example Input: N=4, M=5, S=1, T=4 with edges (1 2 2), (1 3 4), (2 3 1), (2 4 7), (3 4 3)
// Example Output: 6

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t;
    if (!(cin >> n >> m >> s >> t)) {
        return 0;
    }

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;
        if (u == t) break;

        for (const auto& edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    if (dist[t] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dist[t] << "\n";
    }

    return 0;
}
