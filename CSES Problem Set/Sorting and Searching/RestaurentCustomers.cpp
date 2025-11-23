#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<int> start(n), end(n);

    for(int i = 0; i < n; i++){
        cin>>start[i] >> end[i];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int count = 0;
    int mc = 0;

    while(i < n && j < n){
        if(start[i] < end[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        mc = max(mc, count);
    }

    cout<<mc;

    return 0;
}