#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis){
    vis[node] = true;

    for(auto it : adj[node]){
        if(!vis[node]){
            if(!dfs(it, node, adj, vis)){
                return false;
            }
        }
        else if(it != node){
            return true;
        }
    }
    return false;
}

bool cycle(vector<vector<int>> &adj){
    int V = adj.size();
    vector<bool> vis(V, 0);
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V,E;
    cin>>V>>E;

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++){
        int u,v;
        cin>>u>>v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if(cycle(adj)){
        cout<<"Cycle present";
    }
    else{
        cout<<"Cycle not presenet";
    }
}