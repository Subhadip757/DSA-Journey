#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<vector<char>> ans(n, vector<char>(m, '.'));
    int flag = 1;

    for(int i = 0; i < n; i++){
        if((i & 1) == 0){
            for(int j = 0; j < m; j++){
                ans[i][j] = '#';
            }
        }
        else{
            if(flag){
                ans[i][m - 1] = '#';
            }
            else{
                ans[i][0] = '#';
            }
            flag ^= 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }

    return 0;
}