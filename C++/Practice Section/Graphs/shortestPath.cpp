#include<bits/stdc++.h>
using namespace std;

vector<int> shortest(vector<pair<int, int>> &edges, int n, int m, int s, int t){
    vector<int> adj[n + 1];

    for(int i = 0; i < m; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1);
    vector<int> parent(n + 1);
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto it : adj[front]){
            if(!vis[it]){
                vis[it] = true;
                parent[it] = front;
                q.push(it);
            }
        }
    }

    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int V,E;
    cin>>V>>E;

    vector<pair<int, int>> edges(V);

    for(int i = 0; i < E; i++){
        cin>>edges[i].first>>edges[i].second;
    }

    int s,t;
    cin>>s>>t;

    vector<int> path = shortest(edges, V, E, s, t);

    for(auto node : path){
        cout<<node<<" ";
    }
}