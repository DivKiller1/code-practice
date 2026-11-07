// Problem: Shortest Path in Weighted Graph
// Difficulty: Medium
// Topic: graphs
//
// Description: Find the shortest path from vertex 1 to vertex n in a weighted undirected graph using Dijkstra's algorithm, printing both the minimum total weight and the path of vertices taken.
// Example Input: 5 6 \n 1 2 2 \n 2 5 5 \n 2 3 4 \n 1 4 1 \n 4 3 3 \n 3 5 1
// Example Output: 5 \n 1 4 3 5

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v]
