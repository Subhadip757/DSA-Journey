#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin>>n;
    vector<int> worms(n);
    for(int i = 0; i < n; i++){
        cin>>worms[i];
    }

    for(int i = 1; i < n; i++){
        worms[i] = worms[i] + worms[i - 1];
    }

    cin>>m;

    for(int i = 0; i < m; i++){
        int a;
        cin>>a;
        int ans = lower_bound(worms.begin(), worms.end(), a) - worms.begin();

        if(ans == n){
            cout<<-1<<endl;
        }
        else{
            cout<<ans + 1<<endl;
        }
    }
    return 0;
}