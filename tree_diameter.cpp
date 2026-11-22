// Problem: Tree Diameter
// Difficulty: Medium
// Topic: trees
//
// Description: Given an unweighted tree with N nodes and N-1 edges, find its diameter, which is the length of the longest simple path (number of edges) between any two nodes.
// Example Input: 5 \n 1 2 \n 1 3 \n 2 4 \n 2 5
// Example Output: 3

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, int dist, const vector<vector<int>>& adj, int& max_dist, int& farthest_node) {
    if (dist > max_dist) {
        max_dist = dist;
        farthest_node = u;
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, dist + 1, adj, max_dist, farthest_node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 1) {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_dist = -1;
    int farthest_node = 1;

    // First DFS to find the node farthest from node 1
    dfs(1, 0, 0, adj, max_dist, farthest_node);

    // Second DFS from the farthest node found to determine tree diameter
    int start_node = farthest_node;
    max_dist = -1;
    dfs(start_node, 0, 0, adj, max_dist, farthest_node);

    cout << max_dist << "\n";

    return 0;
}
