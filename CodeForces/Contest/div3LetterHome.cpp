#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int min_x = a[0];
        int max_x = a[n - 1];

        int steps = (max_x - min_x) + min(abs(s - min_x), abs(s - max_x));
        cout << steps << endl;
    }
    return 0;
}