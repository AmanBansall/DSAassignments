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

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int src = 0; 
    
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push({0, src});
    key[src] = 0;

    int mstWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;
        mstWeight += key[u];

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (inMST[v] == false && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "\nEdges in MST:" << endl;
    for (int i = 1; i < V; ++i) {
        if(parent[i] != -1)
            cout << parent[i] << " -- " << i << " == " << key[i] << endl;
    }
    cout << "Total Cost of MST: " << mstWeight << endl;

    return 0;
}