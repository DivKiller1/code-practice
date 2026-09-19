// Problem: Diameter of an Undirected Tree
// Difficulty: Medium
// Topic: trees
//
// Description: Given an unweighted undirected tree with N nodes and N-1 edges, calculate the diameter of the tree, which is the length of the longest path between any two nodes.
// Example Input: 5
// 1 2
// 1 3
// 2 4
// 2 5
// Example Output: 3

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Helper function using BFS to find the farthest node from a given start node and its distance
pair<int, int> bfs(int startNode, int n, const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(startNode);
    dist[startNode] = 0;

    int farthestNode = startNode;
    int maxDist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] > maxDist) {
            maxDist = dist[u];
            farthestNode = u;
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return {farthestNode, maxDist};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
