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
        for (auto it : adj[i])
        {
            int node = it[0];
            int wt = it[1];
            pq.push({wt, {i, node}});
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

int main() {
    int V = 4;
    vector<vector<int>> adj[V];

    // Example graph:
    // 0 -- 1 -- 1
    // 0 -- 3 -- 2
    // 1 -- 3 -- 2
    // 1 -- 6 -- 3
    // 2 -- 4 -- 3

    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});

    adj[0].push_back({2, 3});
    adj[2].push_back({0, 3});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 6});
    adj[3].push_back({1, 6});

    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});

    cout << "Minimum Spanning Tree Cost: " << spanningTree(V, adj) << endl;

    return 0;
}