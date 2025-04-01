#include <bits/stc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<bool> &vis, int st, int prev)
{
    vis[st] = true;

    for (auto it : adj[st])
    {
        if (dfs(adj, vis, it, st))
        {
            return true;
        }
    }
}

bool cycle(vector<int> adj[], int V, int prev)
{
}

int main()
{
    int V = 8;
    int E = 7;

    vector<int> adj[V];

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(5);
    adj[2].push_back(6);
    adj[3].push_back(7);
    adj[3].push_back(4);
    adj[7].push_back(8);

    if (cycle(adj, V))
    {
        cout << "Present";
    }
    else
    {
        cout << "Not Present";
    }
}