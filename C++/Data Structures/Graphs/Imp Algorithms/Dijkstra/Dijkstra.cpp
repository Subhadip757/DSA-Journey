#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initialize distance vector
    vector<int> dist(vertices, INT_MAX);

    // Priority queue to store (distance, node) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance to source is 0
    dist[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        // Get the node with the smallest distance
        int nodeDistance = pq.top().first;
        int topNode = pq.top().second;
        pq.pop();

        // Traverse all neighbors of the current node
        for (auto neighbour : adj[topNode])
        {
            int neighbourNode = neighbour.first;
            int edgeWeight = neighbour.second;

            // Relaxation step
            if (nodeDistance + edgeWeight < dist[neighbourNode])
            {
                // Update the distance and push into the priority queue
                dist[neighbourNode] = nodeDistance + edgeWeight;
                pq.push(make_pair(dist[neighbourNode], neighbourNode));
            }
        }
    }

    return dist;
}

int main()
{
    // Example input
    int vertices = 5; // Number of vertices
    int edges = 7;    // Number of edges
    int source = 0;   // Source node

    // Graph represented as a vector of edges: {u, v, weight}
    vector<vector<int>> vec = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 5},
        {2, 4, 9},
        {3, 4, 4}};

    // Call Dijkstra's algorithm
    vector<int> distances = dijkstra(vec, vertices, edges, source);

    // Print the shortest distances from the source node
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < vertices; i++)
    {
        if (distances[i] == INT_MAX)
        {
            cout << "Node " << i << ": INF\n";
        }
        else
        {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}