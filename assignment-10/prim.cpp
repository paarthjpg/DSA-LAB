#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj; 
    // each pair = (neighbor, weight)

    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});    // undirected
    }

    void primMST(int start) {
        vector<int> key(V, INT_MAX);      // minimum weight edge to connect
        vector<int> parent(V, -1);        // stores MST structure
        vector<bool> inMST(V, false);     // node already picked?

        // Min-heap storing {key, vertex}
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            // Relax edges
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        // Print MST
        cout << "Edge : Weight\n";
        for (int i = 0; i < V; i++) {
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST(0);

    return 0;
}
