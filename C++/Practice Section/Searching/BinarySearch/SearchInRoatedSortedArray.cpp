#include <iostream>
using namespace std;

int searchInRotatedSortedArray(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = start+(end - start)/2;

    while(start < end){
        if(target == arr[mid]){
            return mid;
        }
        if(arr[mid] > target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end -start)/2;
    }
    return start;
}

int main(){
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int result = searchInRotatedSortedArray(arr, 7,1);
    cout<<result<<endl;
}