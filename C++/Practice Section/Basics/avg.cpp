#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    vector<vector<int>> arr = { {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};

    int n = arr.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[j][i]<<" ";
        }
    }
    return 0;
}