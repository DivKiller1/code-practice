// Problem: Tree Diameter
// Difficulty: Medium
// Topic: trees
//
// Description: Given an undirected tree with N nodes and N-1 edges, find the diameter of the tree, which is the length of the longest path between any pair of nodes.
// Example Input: 5\n1 2\n1 3\n2 4\n2 5
// Example Output: 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_diameter = 0;

int dfs(int u, int p, const vector<vector<int>>& adj) {
    int max1 = 0;
    int max2 = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        int h = dfs(v, u, adj);
        if (h > max1) {
            max2 = max1;
            max1 = h;
        } else if (h > max2) {
            max2 = h;
        }
    }
    max_diameter = max(max_diameter, max1 + max2);
    return max1 + 1;
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

    dfs(1, 0, adj);

    cout << max_diameter << "\n";

    return 0;
}
