#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &adj, stack<int> &s, vector<bool> &vis, int node){
    vis[node] = true;

    for(int it : adj[node]){
        if(!vis[it]){
            dfs(adj, s, vis, it);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &adj, int V){
    stack<int> s;
    vector<bool> vis(V, false);
    vector<int> res;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(adj, s, vis, i);
        }
    }

    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main(){
    int vertices,edges;
    cout<<"Enter vertices and edges: ";
    cin>>vertices>>edges;

    vector<vector<int>> adj(vertices);
    vector<bool> vis(vertices, false);

    cout<<"Enter directed edges (u -> v): \n";
    for(int i = 0; i < edges; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<int> res = topologicalSort(adj, vertices);

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
}