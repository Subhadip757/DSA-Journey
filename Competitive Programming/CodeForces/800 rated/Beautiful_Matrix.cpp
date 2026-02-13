#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> arr(5, vector<int>(5, 0));
    int idxRow = 0, idxCol = 0;
    int midRow = 2, midCol = 2;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1){
                idxRow = i;
                idxCol = j;
            }
        }
    }

    cout<<abs(idxRow - midRow) + abs(idxCol - midCol);

    return 0;
}