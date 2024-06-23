#include <iostream>

using namespace std;

bool binarySearch(int *arr, int s, int e, int k){
    if(s > e){
        return false;
    }
    
    int mid = s + (e - s)/2;

    if(arr[mid] < k){
        return binarySearch(arr, mid + 1, e, k);
    }else{
        return binarySearch(arr, s, mid - 1, k);
    }
}

int main(){
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 6;
    bool ans = binarySearch(arr, 0, 5, key);
    
    if(ans){
        cout<<"Present"<<endl;
    }else{
        cout<<"Not present"<<endl;
    }
}