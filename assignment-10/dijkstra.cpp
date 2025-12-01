#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // remove for directed graph
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);

        // min-heap stores {distance, node}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // If this entry is outdated, ignore it
            if (d != dist[u])
                continue;

            // Relaxation
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " = " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    g.dijkstra(0);

    return 0;
}
