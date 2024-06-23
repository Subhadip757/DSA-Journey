#include <iostream>
using namespace std;

int lastOcc(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = start +(end - start)/2;
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
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int arr[10] = {1, 2, 2, 3, 4, 4, 4, 4, 5};
    int result = lastOcc(arr, 10, 2);
    cout<<result << endl;
}
