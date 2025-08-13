#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    for(int i = start; i <= mid; i++){
        if(arr[i] > arr[mid]){
            swap(arr[i], arr[mid]);
        }
    }
}

void mergeSort(vector<int> &arr, int start, int end){
    int mid = start + (end - start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}
int main()
{
    return 0;
}