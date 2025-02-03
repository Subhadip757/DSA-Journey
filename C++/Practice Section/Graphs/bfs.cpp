#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> bfs(vector<int> adj[], int startNode, int V){
    vector<bool> vis(V, 0);
    vis[startNode] = 1;
    
    vector<int> res;
    queue<int> q;
    q.push(startNode);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    } 
    return res;
}

int main(){
    int V = 6;

    vector<int> adj[V];
    vector<bool> vis(V, 0);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);

    vector<int> ans = bfs(adj, 0, V);

    for(int i = 0; i < V; i++){
        cout<<ans[i]<<" ";
    }

}