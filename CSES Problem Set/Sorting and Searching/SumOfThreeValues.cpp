#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> threeSumValues(vector<int> &arr, int k){
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;

        while(j < k){
            while(j < k && arr[j] == arr[j - 1]) continue;
            while(j < k && arr[k] == arr[k + 1]) continue;

            int sum = arr[i] + arr[j] + arr[k];

            if(sum == k){
                return {i + 1, j + 1, k + 1};
            }
            else if(sum > k){
                k--;
            }
            else{
                j++;
            }
        }
    }

    return {};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    vector<int> ans = threeSumValues(arr, k);
    if(ans.empty()){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }


    return 0;
}