#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void DFS(vector<vector<int> > adj, vector<bool>& visited, int node){
    cout << node << " ";
    visited[node] = true;
    for(int n :adj[node]){
        if(!visited[n]){
            DFS(adj,visited,n);
        }
    }
}

void dfsStart(vector<vector<int> > adj){
    vector<bool>  visited(adj.size(), false);
    for(int i=1;i<adj.size();i++){
        if(!visited[i]){
            DFS(adj,visited, i);
        }
    }
}

void addEdge(vector<vector<int> >& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    vector<vector<int> > adj(6);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,2);
    addEdge(adj,4,5);
    addEdge(adj,5,1);

    dfsStart(adj);
}

