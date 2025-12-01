#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u != v) {
            if (rank[u] < rank[v])
                parent[u] = v;
            else if (rank[u] > rank[v])
                parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
};

class Edge {
public:
    int u, v, wt;
};

bool cmp(Edge a, Edge b) {
    return a.wt < b.wt; // sort by weight
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(V);

    int mstWeight = 0;
    vector<Edge> mst;

    // Step 2: Pick edges in sorted order
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].wt;

        // Step 3: Check if they belong to different components
        if (dsu.findParent(u) != dsu.findParent(v)) {
            mst.push_back(edges[i]); // add to MST
            mstWeight += wt;
            dsu.unionSet(u, v);
        }
    }

    // Output MST
    cout << "\nEdges in MST:\n";
    for (auto e : mst) {
        cout << e.u << " -- " << e.v << " == " << e.wt << endl;
    }

    cout << "\nTotal weight of MST = " << mstWeight << endl;

    return 0;
}
