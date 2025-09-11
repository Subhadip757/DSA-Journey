#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        int x = abs(a - b);
        int y = abs(c - d);

        if(x == y){
            cout<<"YES"<<endl;
        }
        else if(x % 2 == 0 && y % 2 == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}