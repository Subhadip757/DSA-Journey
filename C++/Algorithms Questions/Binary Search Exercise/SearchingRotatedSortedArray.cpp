#include <iostream>
#include <vector>
using namespace std;

int getPivot(int arr[], int size){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start < end){
        if(arr[mid] > arr[0]){
            start = mid + 1;
        }else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int binarySearch(int arr[], int s,int e, int key){
    int start = s;
    int end = e;
    int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }
        if(key > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end -start)/2;
    }
    return -1;
}

int main(){
    int n = 5;
    int k = 3;
    int arr[n] = {7,8,1,3,5};
    int pivot = getPivot(arr,n);
    if(k >= arr[pivot] && k <= arr[n-1]){
        cout<< binarySearch(arr,pivot, n-1, k)<<endl;
    }else{
        cout<< binarySearch(arr, 0, pivot-1,k)<<endl;
    }
}