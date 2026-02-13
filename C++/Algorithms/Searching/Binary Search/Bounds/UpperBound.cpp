#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int upperBound(vector<int> arr, int n, int target){
    int start = 0;
    int end = n - 1;
    int ans = n;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] > target){
            ans = min(ans, mid);
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 10, 20, 30};
    int n = arr.size();

    int ans = upperBound(arr, n, 8);

    cout<<"Lower bound: "<<ans<<endl;
    return 0;
}