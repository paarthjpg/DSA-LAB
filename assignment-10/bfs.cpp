#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
  private:
    int v;
    vector<vector<int>> adj;
  
  public:
    Graph(int vertices){
      v =vertices;
      adj.resize(v);
    }
    void addEdge(int u, int v){
      adj[u].push_back(v);
      adj[v].push_back(u);  //remove this if directed graph
    }
    void BFS(int start){
      vector<bool> visited(v,false);
      queue<int> q;

      visited[start]= true;
      q.push(start);

      cout<<"BFS Traversal: ";

      while(!q.empty()){
        int node= q.front();
        q.pop();

        cout<<node<<" ";

        for(int i=0; i<adj[node].size(); i++){
          int neighbour= adj[node][i];

          if(!visited[neighbour]){
            visited[neighbour] = true;
            q.push(neighbour);
          }
        }
      }
      cout<< endl;
    }
};
int main(){
  Graph g(5);

  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,3);
  g.addEdge(2,4);

  g.BFS(0);

  return 0;
}