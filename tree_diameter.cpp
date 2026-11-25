// Problem: Tree Diameter
// Difficulty: Medium
// Topic: trees
//
// Description: Given an unweighted, undirected tree with N nodes and N-1 edges, calculate the diameter of the tree, which is the length of the longest path between any pair of nodes.
// Example Input: 5 1 2 1 3 2 4 2 5
// Example Output: 3

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Function to perform BFS and return the farthest node and its distance from the start node
pair<int, int> bfs(int start_node, int n, const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(start_node);
    dist[start_node] = 0;

    int farthest_node = start_node;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] > max_dist) {
            max_dist = dist[u];
            farthest_node = u;
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return {farthest_node, max_dist};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    // Step 1: Find the farthest node from an arbitrary node (node 1)
    pair<int, int> p1 = bfs(1, n, adj);

    // Step 2: Find the farthest node from p1.first to determine the diameter
    pair<int, int> p2 = bfs(p1.first, n, adj);

    cout << p2.second << "\n";

    return 0;
}
