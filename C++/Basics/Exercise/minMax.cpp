#include<iostream>
#include <climits>
using namespace std;

int getMax(int arr[], int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int getMin(int arr[], int n){
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int linearSearch(int arr[],int target){
    for(int i=0;i<=sizeof(arr);i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}

int main(){
    // int size;
    // cin>>size;

    // int numbers[100];

    // for(int i=0;i<size;i++){
    //     cin>>numbers[i];
    // }
    // cout<<"Maximum: "<<getMax(numbers,size)<<endl;
    // cout<<"Maximum: "<<getMin(numbers,size)<<endl;

    int array[10] = {1,2,3,4,6,5,7};
    int target = 5;

    cout<<linearSearch(array,target)<<endl;
}