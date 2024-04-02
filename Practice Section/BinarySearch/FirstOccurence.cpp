#include <iostream>
using namespace std;

int firstOccurence(int arr[],int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end){
        if(arr[mid] == target){
            ans = mid;
            end = mid - 1;
        } else if(target > arr[mid]){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end -start)/2;
    }
    return ans;
}

int main(){
    int arr[10] = {1,1,2,2,2,3,3,3,4};
    int result = firstOccurence(arr,10,3);
    cout<<result<<endl;
}