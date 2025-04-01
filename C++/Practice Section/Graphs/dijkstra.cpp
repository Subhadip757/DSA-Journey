#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int V, int E, int S)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < V; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[S] = 0;
    pq.push(make_pair(0, S));

    while (!pq.empty())
    {
        int nodeDistance = pq.top().first;
        int topNode = pq.top().second;
        pq.pop();

        for (auto neighbour : adj[topNode])
        {
            int neighbourNode = neighbour.first;
            int edgeWeight = neighbour.second;

            if (nodeDistance + edgeWeight < dist[neighbourNode])
            {
                dist[neighbourNode] = nodeDistance + edgeWeight;
                pq.push(make_pair(dist[neighbourNode], neighbourNode));
            }
        }
    }
    return dist;
}

int main()
{
    int V = 5;
    int E = 8;

    vector<vector<int>> adj = {
        {0, 3, 8},
        {0, 1, 4},
        {0, 2, 6},
        {1, 2, 2},
        {1, 4, 5},
        {2, 3, 5},
        {2, 4, 9},
        {3, 4, 4},
    };

    vector<int> res = dijkstra(adj, V, E, 0);
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == INT_MAX)
        {
            cout << "INF ";
        }
        cout << res[i] << " ";
    }
}