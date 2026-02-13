#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int mlDrink = k * l;
    int firstToast = mlDrink / nl;

    int limes = c * d;
    int salt = p / np;

    int ans = min({firstToast, limes, salt})/n;
    cout<<ans;
    return 0;
}