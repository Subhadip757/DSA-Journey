#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];

        for(int i = 0; i < n; ++i) {
            int q  = (n + 1) - p[i];
            if(i != 0) cout<<" ";
            cout<<q;
        }
        cout<<endl;
    }
    return 0;
}