#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int N = 9;
vector<int> graph[N];

int main() {
    // Input edges
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4},
        {2, 5}, {2, 6}, {2, 7}, {3, 8}
    };

    // Build graph
    for (auto edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    // Step 1: Forcefully select 0 and 2 as satellites
    vector<bool> selected(N, false);
    selected[0] = true;
    selected[2] = true;

    int satelliteCount = 2;

    // Special rule: connection 0–2 counts as 4 satellites
    satelliteCount += 2;

    // Step 2: Check each node's satellite connections
    for (int node = 0; node < N; ++node) {
        int count = 0;
        if (selected[node]) count++;

        for (int neighbor : graph[node]) {
            if (selected[neighbor]) count++;
        }

        if (count < 3) {
            // Not enough satellites, check if connected to node 2
            bool connectedTo2 = false;
            if (node == 2 || find(graph[node].begin(), graph[node].end(), 2) != graph[node].end()) {
                connectedTo2 = true;
            }

            if (!connectedTo2 && !selected[node]) {
                selected[node] = true;
                satelliteCount++;
            }
        }
    }

    cout << "Minimum satellites needed (with special rule): " << satelliteCount << endl;

    // Optional: Print which nodes have satellites
    cout << "Satellite Nodes: ";
    for (int i = 0; i < N; i++) {
        if (selected[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}