#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        x2 -= x1;
        y2 -= y1;
        x3 -= x1;
        y3 -= y1;

        ll diff = (ll)x2 * y3 - (ll)x3 * y2;

        if(diff > 0) cout<<"LEFT\n";
        if(diff < 0) cout<<"RIGHT\n";
        if(diff == 0) cout<<"TOUCH\n";
    }

    return 0;
}