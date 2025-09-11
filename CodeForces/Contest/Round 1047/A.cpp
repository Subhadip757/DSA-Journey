#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(){
    int k, x;
    cin>>k>>x;

    int ans = pow(2, k) * x;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--)
    {
        cout<<solve()<<endl;
    }
    

    return 0;
}