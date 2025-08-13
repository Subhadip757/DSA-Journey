#include <bits/stdc++.h>
using namespace std;

int med(vector<int> &arr){
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());

    int n = temp.size();

    return temp[(n + 1) / 2];
}

int minimum(vector<int> &arr){
    int mini = INT_MAX;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
    }

    return mini;
}

int main()
{
    int t; cin >> t;
    while (t--){
        int k;
        cin >> k;
        vector<int> arr(k); 

        for(int i = 0; i < k; i++){
            cin >> arr[i];
        }

        vector<vector<int> > ans;

        for(int i = 0; i < k; i++){
            vector<int> temp;
            for(int j = i; j < k; j++){
                temp.push_back(arr[j]);
            }
            ans.push_back(temp);
        }

        int maxi = 0;

        for(int i = 0; i < ans.size(); i++){
            vector<int> temp = ans[i];
            int md = med(temp);
            int mn = minimum(temp);

            if(abs(md - mn) > maxi){
                maxi = abs(md - mn);
            }
        }

        cout << maxi << endl;
    }
    return 0;
}