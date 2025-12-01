#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(V);
    int mstWeight = 0;
    cout << "\nEdges in MST:" << endl;

    for (Edge e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            mstWeight += e.weight;
            cout << e.u << " -- " << e.v << " == " << e.weight << endl;
        }
    }

    cout << "Total Cost of MST: " << mstWeight << endl;
    return 0;
}