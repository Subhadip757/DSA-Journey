#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<ll> set1, set2;
    ll target = total / 2;

    for (ll i = n; i >= 1; i--) {
        if (i <= target) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << set1.size() << "\n";
    for (auto x : set1) cout << x << " ";
    cout << "\n";

    cout << set2.size() << "\n";
    for (auto x : set2) cout << x << " ";
    cout << "\n";

    return 0;
}