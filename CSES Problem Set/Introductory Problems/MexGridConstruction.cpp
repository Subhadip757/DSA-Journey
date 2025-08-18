#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;

    vector<vector<int>> ans(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            unordered_set<int> temp;

            for(int k = 0; k < j; k++) temp.insert(ans[i][k]);
            for(int k = 0; k < i; k++) temp.insert(ans[k][j]);

            int val = 0;
            while(temp.count(val)) val++;
            ans[i][j] = val;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}