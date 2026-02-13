#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int64 a, b;
        cin >> a >> b;
        int64 ans_ll = -1;

        int e = 0;
        int64 tmp = b;
        while((tmp % 2) == 0) { ++e; tmp /= 2; }

        if ((a & 1) && (b & 1)) {
            i128 prod = (i128)a * (i128)b + 1;
            ans_ll = (long long)prod;
        } else if (( (a & 1) == 0 ) && (b & 1)) {
            ans_ll = -1;
        } else if ((a & 1) && e == 1) {
            ans_ll = -1;
        } else {
            i128 val = (i128)a * (i128)(b / 2) + 2;
            ans_ll = (long long)val;
        }

        cout << ans_ll << '\n';
    }
    return 0;
}