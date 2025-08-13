#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;

        ll m = max(x, y);
        ll val = 0;

        if(m % 2 != 0){
            if(m == y){
                // bottom edge
                val = m * m - (x - 1);
            }
            else if(m == x){
                // right edge
                val = (m - 1) * (m - 1) + y;
            }
        }
        else{
            if(m == y){
                // top edge
                val = (m - 1) * (m - 1) + x;
            }
            else if(m == x){
                //left edge
                val = m * m - (y - 1);
            }
        }
        cout<<val<<endl;
    }
    return 0;
}