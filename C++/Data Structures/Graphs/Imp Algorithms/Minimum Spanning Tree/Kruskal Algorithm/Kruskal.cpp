#include <bits/stdc++.h>
using namespace std;

int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
    {
        return u;
    }

    // Path compression
    return parent[u] = findParent(parent[u], parent);
}

void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    // mrege
    if (rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else if (rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            pq.push({adj[i][j][1], {i, adj[i][j][0]}});
        }
    }

    int cost = 0;

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        // check if they are in different set
        if (findParent(u, parent) != findParent(v, parent))
        {
            cost += wt;
            unionByRank(u, v, parent, rank);
        }
    }
    return cost;
}