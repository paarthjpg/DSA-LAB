#include <iostream>
#include <vector>
using namespace std;

struct Graph {
    int n;
    bool directed;
    vector<vector<int>> adjMat;
    vector<vector<int>> adjList;
    Graph(int v, bool dir) {
        n = v;
        directed = dir;
        adjMat.assign(n, vector<int>(n, 0));
        adjList.assign(n, vector<int>());
    }
    void addEdge(int u, int v) {
        if (u < 0 || u >= n || v < 0 || v >= n) return;
        adjMat[u][v] = 1;
        adjList[u].push_back(v);
        if (!directed) {
            adjMat[v][u] = 1;
            adjList[v].push_back(u);
        }
    }
    int outDegree(int u) {
        if (u < 0 || u >= n) return 0;
        int d = 0;
        for (int v = 0; v < n; v++) if (adjMat[u][v]) d++;
        return d;
    }
    int inDegree(int u) {
        if (u < 0 || u >= n) return 0;
        int d = 0;
        for (int v = 0; v < n; v++) if (adjMat[v][u]) d++;
        return d;
    }
    int numEdges() {
        int c = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (adjMat[i][j]) c++;
        if (!directed) c /= 2;
        return c;
    }
    void printAdjVertices(int u) {
        if (u < 0 || u >= n) {
            cout << "Invalid vertex\n";
            return;
        }
        cout << "Adjacent vertices of " << u << ": ";
        for (int v : adjList[u]) cout << v << " ";
        cout << "\n";
    }
    void printAdjMat() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << adjMat[i][j] << " ";
            cout << "\n";
        }
    }
    void printAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (int v : adjList[i]) cout << v << " ";
            cout << "\n";
        }
    }
};

int main() {
    int n, m, dirFlag;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Directed graph? (1=yes, 0=no): ";
    cin >> dirFlag;
    Graph g(n, dirFlag == 1);
    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int choice;
    do {
        cout << "\n1. Show adjacency matrix\n";
        cout << "2. Show adjacency list\n";
        cout << "3. Degree (in/out) of a vertex\n";
        cout << "4. Adjacent vertices of a vertex\n";
        cout << "5. Number of edges\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        int v;
        switch (choice) {
            case 1:
                g.printAdjMat();
                break;
            case 2:
                g.printAdjList();
                break;
            case 3:
                cout << "Enter vertex: ";
                cin >> v;
                cout << "Out-degree: " << g.outDegree(v) << "\n";
                if (g.directed) cout << "In-degree: " << g.inDegree(v) << "\n";
                else cout << "In-degree: " << g.outDegree(v) << "\n";
                break;
            case 4:
                cout << "Enter vertex: ";
                cin >> v;
                g.printAdjVertices(v);
                break;
            case 5:
                cout << "Number of edges: " << g.numEdges() << "\n";
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}