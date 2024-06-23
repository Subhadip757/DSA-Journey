#include <iostream>
using namespace std;

// int firstOccurence(int arr[], int n, int key){
//     int s = 0, e = n - 1;
//     int mid = s + (e-s)/2;
//     int ans = -1;

//     while(s <= e){
//         if(arr[mid] == key){
//             ans = mid;
//             e = mid - 1;
//         }
//         else if(key > arr[mid]){
//             s = mid + 1;
//         }
//         else if(key < arr[mid]){
//             e = mid - 1;
//         }
//         mid = s +(e-s)/2;
//     }
//     return ans;
// }

// int lastOccurence(int arr[], int n, int key){
//     int s = 0, e = n - 1;
//     int mid = s + (e-s)/2;
//     int ans = -1;

//     while(s <= e){
//         if(arr[mid] == key){
//             ans = mid;
//             s = mid + 1;
//         }
//         else if(key > arr[mid]){
//             s = mid + 1;
//         }
//         else if(key < arr[mid]){
//             e = mid - 1;
//         }
//         mid = s +(e-s)/2;
//     }
//     return ans;
// }

int firstOcc(int* arr, int s, int e, int target){
    if( s > e){
        return -1;
    }
    int mid = s+(e - s)/2;
    if(arr[mid] == target){
        int left = firstOcc(arr, s, mid-1, target);
        if(left == -1){
            return mid;
        }else{
            return left;
        }
    }
    else if(target > arr[mid]){
        return firstOcc(arr, mid + 1, e, target);
    }else{
        return firstOcc(arr, s, mid + 1, target);
    }
}
int lastOcc(int* arr, int s, int e, int target){
    if( s > e){
        return -1;
    }
    int mid = s + (e - s)/2;
    if(arr[mid] == target){
        int right = lastOcc(arr, mid + 1, e, target);
        if(right == -1){
            return mid;
        }else{
            return right;
        }
    }
    else if(target > arr[mid]){
        return lastOcc(arr, mid + 1, e, target);
    }else{
        return lastOcc(arr, s, mid - 1, target);
    }
}

int main(){
    int even[9] = {1,2,3,3,3,3,3,3,5};

    cout <<"First Occurence of 3 is: "<<firstOcc(even,0,9,3)<<endl;

    cout <<"Last Occurence of 3 is: "<<lastOcc(even,0,9,3)<<endl;

    return 0;
}