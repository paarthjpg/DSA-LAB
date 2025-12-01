#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;          // <-- moved visited here

    Graph(int v) {
        V = v;
        adj.resize(V);
        visited.resize(V, false);  // initialize visited
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);       // remove for directed graph
    }

    // ---- ONLY ONE DFS FUNCTION ----
    void DFS(int node) {
        visited[node] = true;
        cout << node << " ";

        // normal for-loop
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                DFS(neighbor);     // recursive call to SAME function
            }
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1,  3);
    g.addEdge(2, 4);

    cout << "DFS Traversal: ";
    g.DFS(0);

    return 0;
}
