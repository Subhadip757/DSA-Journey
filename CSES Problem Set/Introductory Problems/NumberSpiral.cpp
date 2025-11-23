#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        ll ans = 0;
        ll x, y;
        cin >> x >> y;

        if(x <= y){
            if((y & 1) != 0) ans = (y * y) - (x - 1);
            else ans = (y - 1) * (y - 1) + x;
        }
        else{
            if((x & 1) == 0) ans = (x * x) - (y - 1);
            else ans = (x - 1) * (x - 1) + y;
        }
        cout<<ans<<endl;
    }

    return 0;
}