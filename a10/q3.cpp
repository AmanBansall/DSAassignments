#include <iostream>
#include <vector>

using namespace std;

void dfsUtil(int u, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, visited, adj);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int startNode;
    cout << "Enter start node: ";
    cin >> startNode;

    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfsUtil(startNode, visited, adj);
    cout << endl;

    return 0;
}