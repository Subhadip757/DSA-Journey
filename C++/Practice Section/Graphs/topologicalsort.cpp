#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &adj, stack<int> &s, int node, vector<bool> &vis){
    vis[node] = 1;

    for(int it : adj[node]){
        if(!vis[it]){
            dfs(adj, s, it, vis);
        }
    }
    s.push(node);
}

vector<int> topo(vector<vector<int>> &adj, int V){
    vector<bool> vis(V, 0);
    vector<int> ans;
    stack<int> s;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(adj, s, i, vis);
        }
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){
    int V,E;
    cin>>V>>E;

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<int> ans = topo(adj, V);

    for(int it : ans){
        cout<<it<<" ";
    }
}