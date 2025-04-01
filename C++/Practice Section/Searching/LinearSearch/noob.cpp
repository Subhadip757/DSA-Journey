#include<iostream>
#include<vector>
using namespace std;

int main(){
    int s = 4;
    vector<int> arr(s);

    for(int i = 0; i < s; i++){
        cin>>arr[i];
    }
     
    int k = 1;

    int newVal;
    cin>>newVal;

    for(int i = 0; i <= k; i++){
        if(i == k){
            arr[i] = arr[i + 1];
            arr[i] = newVal;
        }
    }
}