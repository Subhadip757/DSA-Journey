#include<bits/stdc++.h>
using namespace std;

void merge(int start, int mid, int end, vector<int> &arr){
    vector<int> temp;
    int i = start;
    int j = mid + 1;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int ind = 0; ind < temp.size(); ind++){
        arr[start + ind] = temp[ind];
    }
}

void mergeSort(int start, int end, vector<int> &arr){
    if(start < end){
        int mid = start + (end - start)/2;

        mergeSort(start, mid, arr);
        mergeSort(mid + 1, end, arr);

        merge(start, mid, end, arr);
    }
}

int main(){
    vector<int> arr = {8, 3, 1, 9, 13, 18, 11, 25, 21};
    mergeSort(0, arr.size() - 1, arr);

    for(int n : arr){
        cout<<n<<" ";
    }
}