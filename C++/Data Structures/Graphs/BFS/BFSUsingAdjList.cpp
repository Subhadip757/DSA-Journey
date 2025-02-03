#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    queue<int> q;
    vector<int> bfs;
    vis[0] = 1;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Adding edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);

    vector<int> bfsResult = bfsOfGraph(V, adj);

    cout << "BFS traversal starting from node 0:" << endl;
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
