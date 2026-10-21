// Problem: Shortest Path in Weighted Graph
// Difficulty: Medium
// Topic: graphs
//
// Description: Given a weighted directed graph with N nodes and M edges, find the shortest distance from a given source node to all other nodes using Dijkstra's algorithm. If a node is unreachable, print -1.
// Example Input: 5 6 1 \n 1 2 2 \n 1 3 4 \n 2 3 1 \n 2 4 7 \n 3 5 3 \n 4 5 1
// Example Output: 0 2 3 9 6

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

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
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
        pair<long long, int> current = pq.top();
        pq.pop();

        long long d = current.first;
        int u = current.second;

        if (d > dist[u]) continue;

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
            cout << -1;
        } else {
            cout << dist[i];
        }
        cout << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}
