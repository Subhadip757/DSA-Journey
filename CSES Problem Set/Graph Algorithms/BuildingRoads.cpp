#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(int x, vector<int> &parent){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int> &parent){
    a = find(a, parent);
    b = find(b, parent);
    if(a != b) parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, E;
    cin >> n >> E;

    vector<int> parent(n + 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        unite(u, v, parent);
    }

    vector<int> reps;
    for(int i = 1; i <= n; i++){
        if(find(i, parent) == i){
            reps.push_back(i);
        }
    }

    cout<<reps.size() - 1<<"\n";
    for(size_t i = 1; i < reps.size(); i++){
        cout<<reps[0]<<" "<<reps[i]<<"\n";
    }

    return 0;
}