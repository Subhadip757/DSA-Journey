#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<int> dist(V, 1e8); // 1e8 = 10^8
    dist[src] = 0;
    int e = edges.size();

    // relax the edges v - 1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] == 1e8)
                continue;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // detect cycle
    for (int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e8 && dist[u] + w < dist[v])
        {
            // cycle detected;
            return {-1};
        }
    }
    return dist;
}

int main()
{
    int V = 5; // vertices
    int src = 0;

    // Directed graph edges with weights
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, -2},
        {1, 3, 5},
        {2, 3, 2},
        {3, 4, 3}};

    vector<int> result = bellmanFord(V, edges, src);

    if (result.size() == 1 && result[0] == -1)
    {
        cout << "Negative weight cycle detected!\n";
    }
    else
    {
        cout << "Shortest distances from source node " << src << ":\n";
        for (int i = 0; i < V; i++)
        {
            if (result[i] == 1e8)
                cout << "Node " << i << ": INF\n";
            else
                cout << "Node " << i << ": " << result[i] << "\n";
        }
    }

    return 0;
}