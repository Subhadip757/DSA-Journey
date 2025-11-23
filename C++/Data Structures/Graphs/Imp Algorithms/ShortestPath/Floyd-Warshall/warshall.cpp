#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int inf = 1e8;
        
        int n = dist.size();
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != inf && dist[k][j] != inf){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};


int main() {
    int vertices = 5;
    int num_edges = 7;
    int source = 0;
    Solution sol;

    int inf = 1e8;
    vector<vector<int>> adj(vertices, vector<int>(vertices, inf));
    for (int i = 0; i < vertices; i++) adj[i][i] = 0;
    vector<vector<int>> edge_list = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 5},
        {2, 4, 9},
        {3, 4, 4}};
        
    for (auto &e : edge_list) {
        adj[e[0]][e[1]] = e[2];
        adj[e[1]][e[0]] = e[2];
    }

    sol.floydWarshall(adj);

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adj[i][j] == inf)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}