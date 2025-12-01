#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from Source " << src << ":" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "To Vertex " << i << " : ";
        if(dist[i] == INT_MAX) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}