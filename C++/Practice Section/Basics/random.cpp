#include<iostream>
#include<vector>

using namespace std;

void bs(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    vector<int> arr = {9, 4, 1, 8, 6, 10};
    bs(arr, arr.size());

    for( int it : arr){
        cout<<it<<" ";
    }
}