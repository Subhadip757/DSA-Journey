#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    int c = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(i == n/i) c++;
            else{
                c += 2;
            }
        }
    }

    cout<<c<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}