#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &adj, stack<int> &st, vector<bool> &vis, int node){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[node]){
            vis[node] = true;
            dfs(adj, st, vis, it);
        }
    }
    st.push(node);
}

vector<int> topo(vector<vector<int>> &adj, int V){
    stack<int> st;
    vector<bool> vis(V, 0);
    vector<int> ans;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(adj, st, vis, i);
        }
    }

    while(!st.empty()){
        int node = st.top();
        st.pop();
        ans.push_back(node);
    }

    return ans;
}

int main(){
    int V, E;
    cin>>V>>E;

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<int> res = topo(adj, V);

    for(int it : res){
        cout<<it<<" ";
    }
}