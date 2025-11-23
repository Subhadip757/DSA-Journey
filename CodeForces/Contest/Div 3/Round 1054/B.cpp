#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while (t--) {
        int n; 
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end());

        ll ans = 0;
        for (int i = 0; i + 1 < n; i += 2) {
            ll diff = llabs(a[i+1] - a[i]);
            ans = max(ans, diff);
        }
        cout << ans << '\n';
    }
    return 0;
}