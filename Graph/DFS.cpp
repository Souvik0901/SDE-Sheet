#include <bits/stdc++.h>
using namespace std;

// DFS function
void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";   // Print node when visited
    
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Example Graph (Undirected)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    vector<bool> visited(V, false);

    cout << "DFS Traversal starting from node 0: ";
    dfs(0, adj, visited);

    return 0;
}
