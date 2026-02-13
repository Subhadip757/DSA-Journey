#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }

        vector<int> b = a;
    
        sort(a.begin(), a.end());
    
        if(a == b || k > 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}