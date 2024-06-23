#include <iostream>
using namespace std;

int firstOcc(int arr[], int size, int target){
    int start = 0;
    int end = end - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end){
        if(target == arr[mid]){
            ans = mid;
            end = mid - 1;
        }else if(target > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int lastOcc(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end){
        if(target == arr[mid]){
            ans = mid;
            start = mid + 1;
        }else if(target > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
}

int main(){

}