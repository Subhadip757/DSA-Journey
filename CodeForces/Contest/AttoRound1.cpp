#include<bits/stdc++.h>
#include <initializer_list>
using namespace std;

int solve(vector<int> &arr, int N)
{
    sort(arr.begin(), arr.end());
    int mex = 0;

    for (int idx = 0; idx < N; idx++){
        if (arr[idx] == mex){
            mex += 1;
        }
    }

    return mex;
}

int main()
{

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        int count = 0;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] == 0) count++;
        }

        if(count > 0){
            cout<<"NO"<<endl;
            continue;
        }

        string ans = "YES";


        for(int i = 0; i + 3 < n; i++){
            vector<int> temp;
            temp.push_back(abs(arr[i]));
            temp.push_back(abs(arr[i + 1]));
            temp.push_back(abs(arr[i + 2]));

            int mex = solve(temp, temp.size());
            int mini = *min_element(temp.begin(), temp.end());
            int maxi = *max_element(temp.begin(), temp.end());
            
            if(mex != (maxi - mini)){
                ans = "NO";
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}