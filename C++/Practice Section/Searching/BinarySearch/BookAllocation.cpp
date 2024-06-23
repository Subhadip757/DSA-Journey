#include <iostream>
using namespace std;

int isPossibleSol(int arr[], int size, int students,int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<size; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }else{
            studentCount++;
            if(studentCount > students || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int bookAllocation(int arr[], int size, int students){
    int start = 0;
    int sum = 0;
    int ans = -1;

    for(int i=0;i<size; i++){
        sum += arr[i];
    }

    int end = sum;
    int mid = start + (end - start)/2;

    while(start <= end){
        if(isPossibleSol(arr,size,students, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int arr[4] = {10,20,30,40};
    int n = 4;
    int m = 2;
    int result = bookAllocation(arr,n,m);
    cout<<result<<endl;
}