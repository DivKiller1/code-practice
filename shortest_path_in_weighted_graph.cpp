// Problem: Shortest Path in Weighted Graph
// Difficulty: Medium
// Topic: graphs
//
// Description: Given a weighted undirected graph with N vertices and M edges, find the shortest path distance from a source vertex to a destination vertex.
// Example Input: 5 6 1 5 1 2 2 1 3 4 2 3 1 2 4 7 3 5 3 4 5 1
// Example Output: 6

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, src, dst;
    if (!(cin >> n >> m >> src >> dst)) return 0;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();

        long long d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dst] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dist[dst] << "\n";
    }

    return 0;
}
