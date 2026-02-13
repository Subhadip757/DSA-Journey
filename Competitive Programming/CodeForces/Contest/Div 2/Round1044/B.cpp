#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0, mini = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            mini = min(mini, arr[i]);
        }

        if (n == 2) {
            cout << max(arr[0], arr[1]) << endl;
        } else {
            cout << sum + (n - 2) * mini << endl;
        }
    }
    return 0;
}