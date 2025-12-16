#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin>>n>>m;

    if(n == 0 && m == 0){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    if (n == 1 && m == 1) {
        char old = grid[0][0];
        for (char ch = 'A'; ch <= 'D'; ch++) {
            if (ch != old) {
                cout << ch << "\n";
                return 0;
            }
        }
    }

    vector<vector<char>> ans(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool even = (i + j) % 2 == 0;
            
            if(even){
                if(grid[i][j] != 'A') ans[i][j] = 'A';
                else ans[i][j] = 'B';
            }
            else{
                if(grid[i][j] != 'C') ans[i][j] = 'C';
                else ans[i][j] = 'D';
            }
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