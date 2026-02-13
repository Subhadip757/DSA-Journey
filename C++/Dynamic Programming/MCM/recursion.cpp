#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int minCost = INT_MAX;

int cost(int i, int j, vector<int> &arr){
    if(i == j) return 0;

    for(int k = i; k < j; k++){
        int x = arr[i] * arr[k + 1] * arr[j + 1];
        int tc = cost(i, k, arr) + cost(k + 1, j, arr) + x;
        minCost = min(minCost, tc);
    }

    return minCost;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 6, 4, 5, 2};
    
    int n = arr.size();
    cout<<"Minimum cost: "<<cost(0, n - 2, arr);

    return 0;
}