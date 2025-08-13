#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n = 3;
    vector<int> arr;
    vector<vector<int>> ans;

    for(int i = 1; i <= n; i++){
        arr.push_back(i);
    }

    do{
        ans.push_back(arr);
    }
    while(next_permutation(arr.begin(), arr.end()));

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}