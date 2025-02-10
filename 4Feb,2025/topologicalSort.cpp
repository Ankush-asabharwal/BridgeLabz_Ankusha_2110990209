#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void sorts(vector<vector<int> >& adj, vector<bool>& visited, int node, stack<int>& st){
    visited[node] = true;
    for(int n : adj[node]){
        if(!visited[n]){
            sorts(adj,visited,n,st);
        }
    }
    st.push(node);
}
//1234567890

void dfs(vector<vector<int> > adj, int v) {
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    for(int i=1;i<adj.size();i++){
        if(!visited[i]){
            sorts(adj,visited,i,st);
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

void edge(vector<vector<int> > &adj, int u, int v) {
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

int main() {
    vector<vector<int> > adj(6);
    edge(adj,1,2);
    edge(adj,2,3);
    edge(adj,3,4);
    edge(adj,4,2);
    edge(adj,4,5);
    edge(adj,5,1);
    dfs(adj,6);
}