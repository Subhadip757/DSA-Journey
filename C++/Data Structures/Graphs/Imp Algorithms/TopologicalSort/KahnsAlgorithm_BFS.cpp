#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> topoBFS(vector<vector<int>> adj, int V){
    vector<int> inDegree(V, 0);
    queue<int> q;
    vector<int> ans;

    for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    for(int i = 0; i < V; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int it : adj[node]){
            inDegree[it]--;

            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }
    return ans;
}

int main(){
    int V,E;
    cin>>V>>E;

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<int> res = topoBFS(adj, V);

    for(int it : res){
        cout<<it<<" ";
    }
}