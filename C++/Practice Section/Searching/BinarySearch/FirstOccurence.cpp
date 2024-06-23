#include <iostream>
using namespace std;

// int firstOccurence(int arr[],int size, int target){
//     int start = 0;
//     int end = size - 1;
//     int mid = start + (end - start)/2;
//     int ans = -1;

//     while(start <= end){
//         if(arr[mid] == target){
//             ans = mid;
//             end = mid - 1;
//         } else if(target > arr[mid]){
//             start = mid + 1;
//         } else {
//             end = mid - 1;
//         }
//         mid = start + (end -start)/2;
//     }
//     return ans;
// }

//Recursion

int firstOccurence(int* arr, int start, int end, int target){
    if(start > end){
        return -1;
    }
    int mid = start + (end - start)/2;

    if(arr[mid] == target){
        int left = firstOccurence(arr, start, mid - 1, target);
        if(left == -1){
            return mid;
        }else{
            return left;
        }
    }else if(target > arr[mid]){
        return firstOccurence(arr, mid + 1, end, target);
    }else{
        return firstOccurence(arr, start, mid - 1, target);
    }
}

int main(){
    int arr[10] = {1,1,2,2,2,3,3,3,4};
    int result = firstOccurence(arr,0,10,3);
    cout<<result<<endl;
}