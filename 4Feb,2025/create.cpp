#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void edge(vector<vector<int> >& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<vector<int> >& adj){
    for(int i=1; i<adj.size(); i++){
        cout << i << " : ";
        for(int j : adj[i]){
            cout << j << " "; 
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int> > adj(V);
    edge(adj,1,2);
    edge(adj,2,3);
    edge(adj,3,4);
    edge(adj,4,2);
    edge(adj,4,5);
    edge(adj,5,1);
    print(adj);
}