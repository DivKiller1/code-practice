// Problem: Tree Diameter
// Difficulty: Medium
// Topic: trees
//
// Description: Given an undirected tree with N nodes and N-1 edges, calculate the diameter of the tree, which is the length of the longest path between any pair of nodes.
// Example Input: 5\n1 2\n1 3\n2 4\n2 5
// Example Output: 3

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, int dist, const vector<vector<int>>& adj, int& maxDist, int& farthestNode) {
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = u;
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, dist + 1, adj, maxDist, farthestNode);
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

    int farthestNode = 1;
    int maxDist = -1;

    // First DFS to find the node farthest from arbitrary node 1
    dfs(1, 0, 0, adj, maxDist, farthestNode);

    // Second DFS from the farthest node to find the diameter
    int diameter = 0;
    int startNode = farthestNode;
    dfs(startNode, 0, 0, adj, diameter, farthestNode);

    cout << diameter << "\n";

    return 0;
}
