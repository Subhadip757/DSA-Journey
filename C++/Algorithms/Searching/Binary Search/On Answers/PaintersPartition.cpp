#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
int arr[100100];

int check(int mid){
    int last_painter_left = 0;
    int total_painters = 0;

    for(int i = 0; i < n; i++){
        if(last_painter_left >= arr[i]){
            last_painter_left -= arr[i];
       }
       else{
            total_painters++;
            if(total_painters > k) return 0;

            last_painter_left = mid;
            if(last_painter_left >= arr[i]){
                last_painter_left -= arr[i];
            }
            else{
                return 0;
            }
       }
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>> arr[i];
        sum += arr[i];
    }

    int start = 0, end = sum, ans = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(check(mid) == 1){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    cout<<ans<<"\n";


    return 0;
}