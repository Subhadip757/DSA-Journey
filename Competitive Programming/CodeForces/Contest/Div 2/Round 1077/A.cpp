#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> p(n + 1, 0);
        set<int> unused;

        for(int i = 1; i <= n; i++){
            unused.insert(i);
        }

        p[n] = n;
        unused.erase(n);

        for(int i = n - 1; i >= 1; i--){
            int x = p[i + 1] - i;
            int y = p[i + 1] + i;

            if(x >= 1 && unused.count(x)){
                p[i] = x;
                unused.erase(x);
            }
            else{
                p[i] = y;
                unused.erase(y);
            }
        }

        for(int i = 1; i <= n; i++){
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}