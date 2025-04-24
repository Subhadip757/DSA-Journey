#include <bits/stdc++.h>
using namespace std;

vector<int> kahnAlgo(vector<vector<int>> adj, int V)
{
    vector<int> indeg(V, 0);
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return ans;
}

int main()
{
    int V;
    int E;
    cin >> V >> E;
    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = kahnAlgo(adj, V);

    for (int it : ans)
    {
        cout << it << " ";
    }
}