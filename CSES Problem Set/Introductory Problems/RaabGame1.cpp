#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--){
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> a1(n), b1;
        for(int i = 0; i < n; i++){
            a1[i] = i + 1;
        }

        b1.reserve(n);

        int diff = n - (a + b);

         if(diff < 0){
            cout<<"NO\n";
            continue;
        }

        for(int i = 1; i <= diff; ++i) b1.push_back(i);

        for(int i = n; i >= diff + 1; --i) b1.push_back(i);

        if((int)b1.size() != n){
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        for(int x : a1){
            cout<<x<<" ";
        }
        cout<<"\n";
        for(int x : b1){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}