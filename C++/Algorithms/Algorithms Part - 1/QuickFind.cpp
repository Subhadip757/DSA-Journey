#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> ids;

// Quick Find
int root(int i){
    while(i != ids[i]){
        ids[i] = ids[ids[i]];
        i = ids[i];
    }
    return i;
}

bool connected(int p, int q){
    return root(p) == root(q);
}

void Union(int p, int q){
    int i = root(p);
    int j = root(q);
    ids[i] = j;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    ids.resize(n);

    for(int i = 0; i < n; i++){
        ids[i] = i;
    }
    return 0;
}