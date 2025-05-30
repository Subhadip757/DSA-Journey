#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int V, int E, int src)
{
    vector<vector<pair<int, int>>> adj(V);

    for(auto edge : vec){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        auto [currDist, node] = pq.top();
        pq.pop();

        for(auto it : adj[node]){
            auto &[nei, wei] = it;

            if(dist[node] + wei < dist[nei]){
                dist[nei] = dist[node] + wei;
                pq.push({dist[nei], nei});
            }
        }
    }
    return dist;
}

int main()
{
    // Example input
    int vertices = 5; // Number of vertices
    int edges = 7;    // Number of edges
    int source = 0;   // Source node

    // Graph represented as a vector of edges: {u, v, weight}
    vector<vector<int>> vec = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 5},
        {2, 4, 9},
        {3, 4, 4}};

    // Call Dijkstra's algorithm
    vector<int> distances = dijkstra(vec, vertices, edges, source);

    // Print the shortest distances from the source node
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < vertices; i++)
    {
        if (distances[i] == INT_MAX)
        {
            cout << "Node " << i << ": INF\n";
        }
        else
        {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}