#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> adj, int src){
    vector<int> dist(V, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int nei = it.first;
            int w = it.second;

            if(dist[node] + w < dist[nei]){
                dist[nei] = dist[node] + w;
                pq.push({dist[nei], nei});
            }
        }
    }

    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ---------- HARD CODED GRAPH ----------
    // Graph:
    // 0 --2-- 1
    // | \     |
    // 4   1   7
    // |     \ |
    // 2 --3-- 4 --1-- 3

    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    adj[1].push_back({3, 7});
    adj[3].push_back({1, 7});

    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});

    adj[4].push_back({3, 1});
    adj[3].push_back({4, 1});

    int src = 0;

    // Run Dijkstra
    vector<int> dist = dijkstra(V, adj, src);

    // ---------- OUTPUT ----------
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}