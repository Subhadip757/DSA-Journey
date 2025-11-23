#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int x,  n;
        cin>>x>>n;

        int sum = 0;

        while(n--){
            sum += x;
            x = -x;
        }

        cout<<sum<<endl;
    }
    return 0;
}