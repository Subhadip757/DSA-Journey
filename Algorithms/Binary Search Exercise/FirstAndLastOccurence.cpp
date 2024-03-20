#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]){
            s = mid + 1;
        }
        else if(key < arr[mid]){
            e = mid - 1;
        }
        mid = s +(e-s)/2;
    }
    return ans;
}

int lastOccurence(int arr[], int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]){
            s = mid + 1;
        }
        else if(key < arr[mid]){
            e = mid - 1;
        }
        mid = s +(e-s)/2;
    }
    return ans;
}

int main(){
    int even[9] = {1,2,3,3,3,3,3,3,5};

    cout <<"First Occurence of 3 is: "<<firstOccurence(even,9,3)<<endl;

    cout <<"Last Occurence of 3 is: "<<lastOccurence(even,9,3)<<endl;

    return 0;
}