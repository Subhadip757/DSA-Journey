#include<bits/stdc++.h>
using namespace std;

bool isGood(vector<int> &arr){
    int n = arr.size();
    if(n >= 5){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < arr[i + 1] && arr[i + 1] < arr[i + 2] && arr[i + 2] < arr[i + 3] && arr[i + 3] < arr[i + 4]){
                return false;
            }
            if(arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2] && arr[i + 2] > arr[i + 3] && arr[i + 3] > arr[i + 4]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n;
        cin >> n;

        deque<int> dq;
        
        for(int i = 0; i < n; i++){
            int val;cin>>val;
            dq.push_back(val);
        }

        string str = "";
        vector<int> arr;

        for(int i = 0; i < n; i++){
            int left = dq.front();
            int right = dq.back();

            arr.push_back(left);
            dq.pop_front();

            if(isGood(arr)){
                str += 'L';
            }
            else{
                arr.pop_back();
                dq.push_front(left);
                arr.push_back(right);
                dq.pop_back();
                str += 'R';
            }
        }
        cout<<str<<endl;
    }
    return 0;
}