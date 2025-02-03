#include <bits/stdc++.h>
using namespace std;

// DFS Function
void dfsTraversal(vector<vector<int>>& adjMat, vector<bool>& visited, int node) {
    cout << node << " ";
    visited[node] = true;

    for (int i = 0; i < adjMat.size(); i++) {
        if (adjMat[node][i] != 0 && !visited[i]) { // If there's an edge and it's not visited
            dfsTraversal(adjMat, visited, i);
        }
    }
}

// Main function to input the graph and perform DFS
int main() {
    int vertex, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edges;

    vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

    cout << "Enter edges (u v) :\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;  // Unweighted graph (1 represents an edge)
        adjMat[v][u] = 1;  // Since it's an undirected graph
    }

    vector<bool> visited(vertex, false);
    int startNode;
    cout << "Enter starting node for DFS: ";
    cin >> startNode;

    cout << "DFS Traversal: ";
    dfsTraversal(adjMat, visited, startNode);
    cout << endl;

    return 0;
}