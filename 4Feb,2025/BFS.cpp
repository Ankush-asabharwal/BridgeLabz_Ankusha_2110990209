#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void bfs(vector<vector<int> >& adj, int v ){
    queue<int> q;
    vector<bool> visited(v, false);
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<< curr << " ";
        for(int x : adj[curr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<vector<int> >& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    vector<vector<int> > adj(5);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,2);
    addEdge(adj,4,5);
    addEdge(adj,5,1);
    bfs(adj, 5);
}