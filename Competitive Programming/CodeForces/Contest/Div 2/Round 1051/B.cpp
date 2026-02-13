#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int k, vector<int> a, vector<int> b){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        if(n == k){
            cout<<0<<endl;
            continue;
        }

        vector<int> a(n), b(k);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }

        for(int i = 0; i < k; i++){
            cin>>b[i];
    }
        cout<<solve(n, k, a, b)<<endl;
    }
    return 0;
}