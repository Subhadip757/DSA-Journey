#include <bits/stc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // Priority Queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> vis(V, 0);

    vector<int> parent(V);

    int cost = 0;
    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();

        if (!vis[node])
        {
            vis[node] = 1;
            cost += wt;
            parent[node] = par;

            for (int j = 0; j < adj[node].size(); j++)
            {
                int adjNode = adj[node][j][0];
                int edgeWt = adj[node][j][1];

                if (!vis[adjNode])
                {
                    pq.push({edgeWt, {adjNode, node}});
                }
            }
        }
    }
    return cost;
}