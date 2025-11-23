#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int spanningTree(int V, vector<vector<int>> adj[]){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});

    vector<int> vis(V, 0);
    int cost = 0;

    while(!pq.empty()){
        auto [wt, node] = pq.top();
        pq.pop();

        if(!vis[node]){
            vis[node] = 1;
            cost += wt;

            for(auto it : adj[node]){
                int adjNode = it[0];
                int wei = it[1];

                pq.push({wei, adjNode});
            }
        }
    }
    
    return cost;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int V = 5;
    vector<vector<int>> adj[V];

    // Undirected weighted edges
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    cout << "Minimum Spanning Tree Cost: " << spanningTree(V, adj) << endl;

    return 0;
}