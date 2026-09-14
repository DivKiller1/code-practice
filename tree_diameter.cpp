// Problem: Tree Diameter
// Difficulty: Medium
// Topic: trees
//
// Description: Given an undirected tree with N nodes and N-1 edges, calculate the diameter of the tree, which is defined as the maximum length (number of edges) of a simple path between any pair of nodes.
// Example Input: 5 1 2 1 3 2 4 2 5
// Example Output: 3

#include <iostream>
#include <vector>
#include <algorithm>

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
    dfs(1, 0, 0, max_depth, farthest_node, adj);

    int diameter = -1;
    int other_end = farthest_node;
    dfs(farthest_node, 0, 0, diameter, other_end, adj);

    cout << diameter << "\n";

    return 0;
}
