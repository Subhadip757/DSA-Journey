#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, vector<int>> route(int n, int m, vector<vector<int>> adj, vector<bool> &vis){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    vis[1] = true;

    while(!pq.empty()){
        auto[cost, node] = pq.top();
        vector<int> res;
        pq.pop();

        if(node == n) return {cost, res};

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                res.push_back(it);
                pq.push({cost + 1, it});
            }
        }
    }

    return {-1, {}};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1);

    for(int i = 0; i < n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, vector<int>> ans = route(n, m, adj, vis);
    cout<<ans.first<<"\n";
    for(auto num : ans.second){
        cout<<num<<" ";
    }

    return 0;
}