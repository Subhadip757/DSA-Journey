#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> adj, int start){
    int V = adj.size();
    vector<int> dist(V, -1);
    vector<bool> vis(V, 0);

    queue<int> q;
    dist[start] = 0;
    vis[start] = 1;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                dist[it] = dist[node] + 1;
                vis[it] = true;
            }
        }
    }

    return dist;
}

int main() {
    int V = 6;
    int E = 6;

    vector<pair<int, int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<vector<int>> adj(V);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist = shortestPath(adj, 0);

    for(int i = 0; i < dist.size(); i++){
        cout<<dist[i]<<" ";
    }

}