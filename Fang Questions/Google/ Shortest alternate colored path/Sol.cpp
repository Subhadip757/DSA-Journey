#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> shortestAlternateColoredPath(int N, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    // Graph adjacency lists for red and blue edges
    vector<vector<int>> red_adj(N), blue_adj(N);
    for (auto& edge : redEdges) {
        red_adj[edge[0]].push_back(edge[1]);
    }
    for (auto& edge : blueEdges) {
        blue_adj[edge[0]].push_back(edge[1]);
    }

    // Distance array: dist[node][0] for red edge, dist[node][1] for blue edge
    vector<vector<int>> dist(N, vector<int>(2, -1));
    
    // BFS queue: stores the current node and the last color used (0 for red, 1 for blue)
    queue<pair<int, int>> q;
    
    // Start from node 0, with both possible initial edge colors
    dist[0][0] = dist[0][1] = 0;  // Node 0 is already reached with both red and blue as starting points
    q.push({0, 0});  // Start from node 0 with red edge
    q.push({0, 1});  // Start from node 0 with blue edge
    
    while (!q.empty()) {
        int node = q.front().first;
        int color = q.front().second;
        q.pop();
        
        // Explore neighbors based on the color of the edge
        if (color == 0) {
            // Last edge was red, so move along blue edges
            for (int neighbor : blue_adj[node]) {
                if (dist[neighbor][1] == -1) {
                    dist[neighbor][1] = dist[node][0] + 1;
                    q.push({neighbor, 1});
                }
            }
        } else {
            // Last edge was blue, so move along red edges
            for (int neighbor : red_adj[node]) {
                if (dist[neighbor][0] == -1) {
                    dist[neighbor][0] = dist[node][1] + 1;
                    q.push({neighbor, 0});
                }
            }
        }
    }
    
    // Prepare the final answer
    vector<int> answer(N);
    for (int i = 0; i < N; ++i) {
        // The shortest path for node i, if it exists
        if (dist[i][0] == -1 && dist[i][1] == -1) {
            answer[i] = -1;
        } else if (dist[i][0] == -1) {
            answer[i] = dist[i][1];
        } else if (dist[i][1] == -1) {
            answer[i] = dist[i][0];
        } else {
            answer[i] = min(dist[i][0], dist[i][1]);
        }
    }
    
    return answer;
}