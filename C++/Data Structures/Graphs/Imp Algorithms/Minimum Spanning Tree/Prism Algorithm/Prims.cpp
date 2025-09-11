#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // Priority Queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(V, 0);

    int cost = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (!vis[node])
        {
            vis[node] = 1;
            cost += wt;

            for (int j = 0; j < adj[node].size(); j++)
            {
                int adjNode = adj[node][j][0];
                int edgeWt = adj[node][j][1];

                if (!vis[adjNode])
                {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
    }
    return cost;
}

int main()
{
    int V = 5;
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
