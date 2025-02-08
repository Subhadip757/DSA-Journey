#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> &edges, int n, int m, int start, int target){
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto it : adj[front]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
                parent[it] = front;
            }
        }
    }

    vector<int> ans;
    int currNode = target;
    ans.push_back(target);

    while (currNode != start) {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Input number of nodes (n), edges (m), start node, and target node
    int n, m, start, target;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    
    vector<pair<int, int>> edges(m);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    cout << "Enter start and target nodes: ";
    cin >> start >> target;

    // Find shortest path
    vector<int> path = shortestPath(edges, n, m, start, target);

    // Output result
    if (path.empty()) {
        cout << "No path exists from " << start << " to " << target << endl;
    } else {
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}