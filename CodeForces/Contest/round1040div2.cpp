#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    unordered_set<int> s;
    
    for (int val : arr) {
        s.insert(val);
    }

    int mex = 0;
    while (s.count(mex)) {
        mex++;
    }

    return mex;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;

        int sum = 0;
        int mex = 0;
        int score = 0;

        vector<int> arr(n);
        vector<int> temp;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        for(int it : arr){
            if(temp.size() == 1){
                sum += it;
                temp.push_back(it);
            }
            else if (temp.size() > 1){
                mex = solve(temp);
                temp.clear();
            }
            score += max(sum, mex);
        }

        cout<<score<<endl;
    }

    return 0;
}