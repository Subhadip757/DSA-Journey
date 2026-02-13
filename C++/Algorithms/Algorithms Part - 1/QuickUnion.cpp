#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> ids;

//Quick Union (O^2)
bool connected(int p, int q){
    return ids[p] == ids[q];
}

void Union(int p, int q){
    int pid = ids[p];
    int qid = ids[q];

    for(int i = 0; i < ids.size(); i++){
        if(ids[p] == pid) ids[i] = qid;
    }
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