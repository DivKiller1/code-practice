// Problem: Tree Diameter
// Difficulty: Medium
// Topic: trees
//
// Description: Given an unweighted tree with N nodes and N-1 edges, calculate the diameter of the tree, defined as the maximum distance (number of edges) between any pair of nodes.
// Example Input: 5\n1 2\n1 3\n2 4\n2 5
// Example Output: 3

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, int depth, int &max_depth, int &farthest_node, const vector<vector<int>> &adj) {
    if (depth > max_depth) {
        max_depth = depth;
        farthest_node = u;
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, depth + 1, max_depth, farthest_node, adj);
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

    int max_depth = -1;
    int farthest_node = 1;

    // First DFS to find the node farthest from node 1
    dfs(1, 0, 0, max_depth, farthest_node, adj);

    // Second DFS from the farthest node found to determine tree diameter
    int root = farthest_node;
    max_depth = -1;
    dfs(root, 0, 0, max_depth, farthest_node, adj);

    cout << max_depth << "\n";

    return 0;
}
