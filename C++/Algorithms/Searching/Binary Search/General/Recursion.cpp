#include <iostream>

using namespace std;

bool binarySearch(int *arr, int s, int e, int k){
    if(s > e){
        return false;
    }
    int mid = s + (e - s)/2;
    if(arr[mid] == k) return true; 

    if(arr[mid] < k){
        return binarySearch(arr, mid + 1, e, k);
    }else{
        return binarySearch(arr, s, mid - 1, k);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
    bool ans = binarySearch(arr, 0, size - 1, key);
    
    if(ans){
        cout<<"Present"<<endl;
    }else{
        cout<<"Not present"<<endl;
    }
}