#include <iostream>
using namespace std;

int smallestInRotatedArray(int arr[], int size){
    int start = 0;
    int end = size - 1;

    while(start < end){
        int mid = start + (end - start)/2;
        if(arr[mid] > arr[end]){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return arr[start];
}


int main(){
    int arr[7] = {5, 6, 7, 1, 2, 3, 4};
    int result = smallestInRotatedArray(arr, 10);
    cout<<result<<endl;
}