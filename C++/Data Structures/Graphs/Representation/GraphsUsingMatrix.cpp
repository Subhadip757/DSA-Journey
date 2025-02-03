#include<bits/stdc++.h>
using namespace std;

//Adjacency Matrix
//Undirected Unweighted
//Undirected weighted
//Directed Graph
int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    // vector<vector<int>> adjMat(vertex, vector<int> (vertex,0));
    vector<vector<bool>> adjMat(vertex, vector<bool> (vertex,0));

    // int u,v,weight;
    int u,v;
    for(int i = 0; i < edges; i++){
        // cin>>u>>v>>weight;
        cin>>u>>v;
        adjMat[u][v] = 1;
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
}