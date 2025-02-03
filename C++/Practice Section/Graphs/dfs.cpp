#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int node){
    cout<<node<<" ";
    vis[node] = 1;

    for(int i = 0; i < adj.size(); i++){
        if(adj[node][i] != 0 && !vis[i]){
            dfs(adj, vis, i);
        }
    }
}

int main(){
    int v,e;
    cout<<"Enter number of vertices and edges: \n";
    cin>>v>>e;

    vector<vector<int>> adj(v, vector<int>(v, 0));
    vector<bool> vis(v, 0);

    cout<<"\nEnter paths: ";
    for(int i = 0; i < e; i++){
        int u,v;
        cin>>u>>v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(adj, vis, 0);
}