#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int n; // Number of vertices
    vector<vector<int>> adjMatrix;

public:
    // Constructor
    Graph(int n) {
        this->n = n;
        adjMatrix.resize(n, vector<int>(n, 0));
    }

    // Method to add an edge
    void addEdge(int u, int v, bool directed = false) {
        adjMatrix[u][v] = 1;
        if (!directed) {
            adjMatrix[v][u] = 1;
        }
    }

    // Method to print the adjacency matrix
    void printAdjMatrix() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "The adjacency matrix of the graph is:" << endl;
    g.printAdjMatrix();

    return 0;
}
