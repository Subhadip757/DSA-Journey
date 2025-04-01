#include<bits/stc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &adj, stack<int> &st, vector<bool> &vis, int node){
    vis[node] = 1;

    for(auto it : adj[node]){
        int neb = it.first;
        if(!vis[neb]){
            dfs(adj, st, vis, neb);
        }
    }
    st.push(node);
}

void topologicalSort(int n, vector<vector<pair<int,int>>> &adj, int src){
    
}


int main(){

}