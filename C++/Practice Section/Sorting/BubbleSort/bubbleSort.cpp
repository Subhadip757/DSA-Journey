#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr{20,1,8,0,10,15};

    bubbleSort(arr);

    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}