#include <iostream>

using namespace std;

int search(int* arr, int start, int end, int target){
    if(start > end){
        return -1;
    }
    int mid = start + (end - start)/2;
    if(arr[mid] == target){
        return mid;
    }else if(target > arr[mid]){
        return search(arr, mid + 1, end, target);
    }else{
        return search(arr, start, mid - 1, target);
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int index = search(arr, 0, 10, 8);
    cout<<endl;
    cout<<"Target present at:- "<<index<<endl;
    cout<<endl;
}